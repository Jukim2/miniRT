/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/06 13:33:34 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "vector3.h"
#include "utils.h"

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

    // engine->objects.shape->next->next->material = MIRROR;
    // engine->objects.shape->next->next->next->material = MIRROR;

	for (int i = 0; i < WIN_WIDTH; i++)
	{
		for (int j = 0; j < WIN_HEIGHT; j++)
		{
			t_shape		*hitted = NULL;
			pixel_center = add_vector3(top_left_pixel, get_vector3(i * pixel_delta_x, j * pixel_delta_y, 0));
			ray.origin = get_vector3(0, 0, 0); // camera center;

			t_vector3 color_vector_sum = get_vector3(0,0,0);
			for (int i = 0; i < 10; i++)
			{
				t_vector3 sample_pixel = add_vector3(pixel_center, get_vector3((-0.5 + random_double_zerone()) * pixel_delta_x, (-0.5 + random_double_zerone()) * pixel_delta_y, 0));
				ray.direction = get_unit_vector3(subtract_vector3(sample_pixel, get_vector3(0, 0, 0)));			
				color_vector_sum = add_vector3(color_vector_sum, raytrace(ray, engine->objects.shape, 50, &hitted));
			}
			color_vector_sum = multiple_vector3(0.1, color_vector_sum);
			if (hitted)
			{
				color_vector_sum = add_vector3(color_vector_sum, multiple_vector3(0.2, hitted->rgb));
				if (color_vector_sum.x > hitted->rgb.x)
					color_vector_sum.x = hitted->rgb.x;
				if (color_vector_sum.y > hitted->rgb.y)
					color_vector_sum.y = hitted->rgb.y;
				if (color_vector_sum.z > hitted->rgb.z)
					color_vector_sum.z = hitted->rgb.z;
			}
			engine->img.addr[(WIN_HEIGHT - j - 1) * engine->img.line_length / 4 + (WIN_WIDTH - i)] = convert_color_vector3(color_vector_sum);
		} 
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img.ptr, 0, 0);
	mlx_loop(engine->mlx);
}
