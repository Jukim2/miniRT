/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 17:22:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "vector3.h"

/* TODO: error handling when fov == 0 or 180 */
/* TODO: handle window ratio */

void	execute_engine(t_engine *engine)
{
	t_vector3	pixel_center;
	t_ray		ray;
	
	ray.origin = engine->objects.camera.coord;
	for (int i = 0; i < WIN_WIDTH; i++)
	{
		for (int j = 0; j < WIN_HEIGHT; j++)
		{
			pixel_center = add_vector3(engine->display.top_left_pixel, \
										get_vector3(i * engine->display.pixel_delta[WIDTH], j * engine->display.pixel_delta[HEIGHT], 0));
			ray.direction = add_vector3(pixel_center, ray.origin);
			ray.direction = get_unit_vector3(ray.direction); // get unit_vector

			// t_vector3 color_vector = get_color_vector3(ray);
			t_vector3 color_vector = get_color(ray, engine->objects.shape);
			engine->img.addr[(WIN_HEIGHT - 1 - j) * engine->img.line_length / 4 + (i)] = convert_color_vector3(color_vector); 
		} 
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img.ptr, 0, 0);
	mlx_loop(engine->mlx);
}
