/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:22:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 10:54:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "numft.h"
#include <math.h>

static void	init_objects(t_objects *objects)
{
	ft_bzero(objects, sizeof(t_objects));
}

static int	init_display_settings(t_engine *e)
{
	if (WIN_H <= 0 || WIN_W <= 0)
		term_engine("Win height and width must bigger than zero", &e->objs, 0);
	e->display.res[WD] = WIN_W;
	e->display.res[HT] = WIN_H;
	e->display.ar = WIN_W / WIN_H;
	e->display.vport[WD] = 2.0 * tan(get_radian(e->objs.camera.fov) / 2.);
	e->display.vport[HT] = e->display.vport[WD] / WIN_W * WIN_H;
	e->display.bot_lt_px = vec3(-e->display.vport[WD] / 2. \
								+e->display.vport[WD] / WIN_W * 0.5, \
								-e->display.vport[HT] / 2. \
								+e->display.vport[HT] / WIN_H * 0.5, \
								-1.);
	e->display.px_dt[WD] = vec3(e->display.vport[WD] / WIN_W, 0, 0);
	e->display.px_dt[HT] = vec3(0, e->display.vport[HT] / WIN_H, 0);
	e->display.rot_quat = get_rot_quat(vec3(0, 0, -1), e->objs.camera.forward);
	if (doublecmp(dot_vec3(vec3(0, 0, -1), e->objs.camera.forward), 0) < 0)
		e->display.inversion = TRUE;
	else
		e->display.inversion = FALSE;
	e->display.bot_lt_px = rot_vec3(e->display.bot_lt_px, e->display.rot_quat);
	e->display.px_dt[WD] = rot_vec3(e->display.px_dt[WD], e->display.rot_quat);
	e->display.px_dt[HT] = rot_vec3(e->display.px_dt[HT], e->display.rot_quat);
	return (1);
}

int	init_engine(t_engine *e, char *filename)
{
	init_objects(&e->objs);
	if (!parse(&e->objs, filename))
		return (0);
	init_display_settings(e);
	e->mlx = mlx_init();
	if (!e->mlx)
		term_engine("mlx init error", &e->objs, 0);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "miniRT");
	if (!e->win)
		term_engine("mlx_window_error", &e->objs, 0);
	e->img.ptr = mlx_new_image(e->mlx, WIN_W, WIN_H);
	if (!e->img.ptr)
	{
		mlx_destroy_window(e->mlx, e->win);
		term_engine("mlx_img_error", &e->objs, 0);
	}
	e->img.addr = (unsigned int *)mlx_get_data_addr(\
		e->img.ptr, &e->img.bpp, &e->img.line_len, &e->img.endian);
	return (1);
}
