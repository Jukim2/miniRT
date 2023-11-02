/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/02 21:28:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "color.h"
#include "numft.h"


/* TODO: error handling when fov == 0 or 180 */
/* TODO: handle window ratio */

int	press_key(int keycode, void *ptr)
{
	if (keycode == KEY_ESC)
		terminate_engine(ptr);
	return (0);
}

static void	set_vport_img(t_engine *e)
{
	int		x;
	int		y;
	int		width;
	int		color;

	width = e->img.line_len / 4;
	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (e->display.inversion)
				color = get_color(e, WIN_W - x - 1, WIN_H - y - 1);
			else
				color = get_color(e, x, y);
			e->img.addr[(WIN_H - y - 1) * width + x] = color;
			y++;
		}
		x++;
	}
	ft_putstr_fd("done\n", 1);
}

void	execute_engine(t_engine *e)
{
	set_vport_img(e);
	mlx_key_hook(e->win, press_key, (void *)e);
	mlx_hook(e->win, BTN_EXIT, 0, &terminate_engine, (void *)e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	mlx_loop(e->mlx);
}
