/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 12:02:05 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "vector3.h"

#include <stdio.h>
void	execute_engine(t_engine *engine)
{
	float	focal_length = 1.f; // 카메라의 초점거리
	float	viewport_height = 5.f;
	float	viewport_width = 10.f;
	float	pixel_delta_x = viewport_width / 1024;
	float	pixel_delta_y = viewport_height / 512;

	t_vector3	top_left_pixel;
	top_left_pixel.x = -viewport_width / 2. + pixel_delta_x * 0.5;
	top_left_pixel.y = -viewport_height / 2. + pixel_delta_y * 0.5;
	top_left_pixel.z = -focal_length;

	t_vector3	pixel_center;
	t_ray		ray;

	for (int i = 0; i < WIN_WIDTH; i++)
	{
		for (int j = 0; j < WIN_HEIGHT; j++)
		{
			pixel_center = add_vector3(top_left_pixel, get_vector3(i * pixel_delta_x, j * pixel_delta_y, 0));
			ray.origin = get_vector3(0, 0, 0); // camera center;
			ray.direction = subtract_vector3(pixel_center, get_vector3(0, 0, 0));
			ray.direction = get_unit_vector3(ray.direction); // get unit_vector

			// t_vector3 color_vector = get_color_vector3(ray);
			t_vector3 color_vector = get_color(ray, engine->objects.shape);
			engine->img.addr[(WIN_HEIGHT - j) * engine->img.line_length / 4 + (WIN_WIDTH - i)] = convert_color_vector3(color_vector); 
		} 
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img.ptr, 0, 0);
	mlx_loop(engine->mlx);
}
