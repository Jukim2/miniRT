/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:22:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 17:24:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include <math.h>

#define PI 3.141592


void	initialize_objects(t_objects *objects)
{
	ft_bzero(objects, sizeof(t_objects));
}

double get_radian(double degrees)
{
	return (degrees * PI / 180.0);
}

int	init_display_settings(t_engine *engine)
{
	double	fov;
	
	fov = get_radian(engine->objects.camera.fov);
	engine->display.resolution[WIDTH] = WIN_WIDTH;
	engine->display.resolution[HEIGHT] = WIN_HEIGHT;
	engine->display.aspect_ratio = WIN_WIDTH / WIN_HEIGHT;
	engine->display.viewport[WIDTH] = 2.0 * tan(fov);
	engine->display.viewport[HEIGHT] = engine->display.viewport[WIDTH] / WIN_WIDTH * WIN_HEIGHT;
	engine->display.pixel_delta[WIDTH] = engine->display.viewport[WIDTH] / WIN_WIDTH;
	engine->display.pixel_delta[HEIGHT] = engine->display.viewport[HEIGHT] / WIN_HEIGHT;
	engine->display.top_left_pixel = get_vector3(-engine->display.viewport[WIDTH] / 2. + engine->display.pixel_delta[WIDTH] * 0.5, \
												-engine->display.viewport[HEIGHT] / 2. + engine->display.pixel_delta[HEIGHT] * 0.5, \
												-1.0);
}

int	init_engine(t_engine *engine, char *config)
{
	initialize_objects(&engine->objects);
	parse(&engine->objects, config);
	init_display_settings(engine);
	engine->mlx = mlx_init();
	engine->win = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	engine->img.ptr = mlx_new_image(engine->mlx, WIN_WIDTH, WIN_HEIGHT);
	engine->img.addr = (unsigned int *)mlx_get_data_addr(\
						engine->img.ptr, &engine->img.bits_per_pixel, \
						&engine->img.line_length, &engine->img.endian);
	return (1);
}
