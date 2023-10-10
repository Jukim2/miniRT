/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 14:55:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "color.h"
#include "vec3.h"

/* TODO: error handling when fov == 0 or 180 */
/* TODO: handle window ratio */

int	press_key(int keycode, void *ptr)
{
	(void) ptr;
	if (keycode == KEY_ESC)
		terminate_engine(ptr);
	return (0);	
}

int	exit_(void)
{
	exit(0);
	return (0);
}

static void	set_vport_img(t_engine *e)
{
	int		x;
	int		y;
	int		width;

	width = e->img.line_len / 4;
	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			e->img.addr[(WIN_H - y - 1) * width + x] = get_color(e, x, y);
			y++;
		}
		x++;
	}
}

void	execute_engine(t_engine *e)
{
	set_vport_img(e);
	mlx_key_hook(e->win, press_key, e);
	mlx_hook(e->win, BTN_EXIT, 0, &exit_, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	mlx_loop(e->mlx);
}
