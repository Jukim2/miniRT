/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:22:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 12:01:18 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"

void	initialize_objects(t_objects *objects)
{
	ft_bzero(objects, sizeof(t_objects));
}

int	init_engine(t_engine *engine, char *config)
{
	initialize_objects(&engine->objects);
	parse(&engine->objects, config);
	engine->mlx = mlx_init();
	engine->win = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	engine->img.ptr = mlx_new_image(engine->mlx, WIN_WIDTH, WIN_HEIGHT);
	engine->img.addr = (unsigned int *)mlx_get_data_addr(\
						engine->img.ptr, &engine->img.bits_per_pixel, \
						&engine->img.line_length, &engine->img.endian);
	return (1);
}
