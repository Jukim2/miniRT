/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/08 15:08:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "raytrace.h"
#include "color.h"
#include "vec3.h"

/* TODO: error handling when fov == 0 or 180 */
/* TODO: handle window ratio */

void	execute_engine(t_engine *e)
{
	int		i;
	int		j;
	t_vec3	px_center;
	t_vec3	offset;

	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			offset = vec3(i * e->display.px_dt[WD], \
							j * e->display.px_dt[HT], 0);
			px_center = add_vec3(e->display.bot_lt_px, offset);
			e->img.addr[(WIN_H - j - 1) * e->img.line_len / 4 + i] = \
								convert_color_vec3(get_color(e, px_center));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	mlx_loop(e->mlx);
}
