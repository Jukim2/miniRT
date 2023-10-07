/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:22:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/07 16:35:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "utils.h"
#include <math.h>

static void	initialize_objects(t_objects *objects)
{
	ft_bzero(objects, sizeof(t_objects));
}

static int	init_display_settings(t_engine *e)
{
	double	fov;

	fov = get_radian(e->objs.camera.fov);
	e->display.res[WD] = WIN_W;
	e->display.res[HT] = WIN_H;
	e->display.ar = WIN_W / WIN_H;
	e->display.vport[WD] = 2.0 * tan(fov);
	e->display.vport[HT] = e->display.vport[WD] / WIN_W * WIN_H;
	e->display.px_dt[WD] = e->display.vport[WD] / WIN_W;
	e->display.px_dt[HT] = e->display.vport[HT] / WIN_H;
	e->display.top_lt_px = vec3(-e->display.vport[WD] / 2. \
								+e->display.px_dt[WD] * 0.5, \
								-e->display.vport[HT] / 2. \
								+e->display.px_dt[HT] * 0.5, \
								-1.0);
	return (1);
}

int	init_engine(t_engine *e, char *conf)
{
	initialize_objects(&e->objs);
	parse(&e->objs, conf);
	init_display_settings(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "miniRT");
	e->img.ptr = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->img.addr = (unsigned int *)mlx_get_data_addr(e->img.ptr, \
													&e->img.bpp, \
													&e->img.line_len, \
													&e->img.endian);
	return (1);
}
