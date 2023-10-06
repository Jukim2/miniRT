/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/06 16:30:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "vec3.h"
#include "utils.h"
#include <math.h>

#include <stdio.h>

/* TODO: error handling when fov == 0 or 180 */
/* TODO: handle window ratio */

void	execute_engine(t_engine *engine)
{
	t_vec3	pixel_center;
	t_ray	ray;

    // engine->objects.shape->next->next->material = MIRROR;
    // engine->objects.shape->next->next->next->material = MIRROR;

	ray.origin = engine->objects.camera.coord;
	
	for (int i = 0; i < WIN_WIDTH; i++)
	{
		for (int j = 0; j < WIN_HEIGHT; j++)
		{
			// gyoon

			pixel_center = add_vec3(engine->display.top_left_pixel, \
										vec3(i * engine->display.pixel_delta[WIDTH], j * engine->display.pixel_delta[HEIGHT], 0));
			/* add q */
			t_vec3 c = cross_vec3(vec3(0, 0, -1), engine->objects.camera.forward_vector);
			c = norm_vec3(c);

			double cosine = dot_vec3(vec3(0, 0, -1), engine->objects.camera.forward_vector);
			double s_half = sqrt((1.0 - cosine) / 2.0);
			double c_half = sqrt((1.0 + cosine) / 2.0);
			
			// q = cos(θ/2) + (x * sin(θ/2), y * sin(θ/2), z * sin(θ/2))
			t_quat q = quat(c_half, c.x * s_half, c.y * s_half, c.z * s_half);
			q = norm_quat(q);

			t_quat a = quat(0, ray.direction.x, ray.direction.y, ray.direction.z);
			// t_quat rotated = q * a * q-1;
			t_quat temp = mult_quat(q, a);
			t_quat conjugate = get_conj_quat(q);
			t_quat rotated = mult_quat(temp, conjugate);
			ray.direction = norm_vec3(vec3(rotated.v.x, rotated.v.y, rotated.v.z));

			// jukim2
			t_shape		*hitted = NULL;
			t_vec3 color_vector_sum = vec3(0,0,0);
			for (int i = 0; i < 10; i++)
			{
				t_vec3 sample_pixel = add_vec3(pixel_center, vec3((-0.5 + random_double_zerone()) * engine->display.pixel_delta[WIDTH], (-0.5 + random_double_zerone()) * engine->display.pixel_delta[HEIGHT], 0));
				ray.direction = norm_vec3(sub_vec3(sample_pixel, vec3(0, 0, 0)));			
				color_vector_sum = add_vec3(color_vector_sum, raytrace(ray, engine->objects.shape, 50, &hitted));
			}
			color_vector_sum = scale_vec3(0.1, color_vector_sum);
			if (hitted)
			{
				color_vector_sum = add_vec3(color_vector_sum, scale_vec3(0.2, hitted->rgb));
				if (color_vector_sum.x > hitted->rgb.x)
					color_vector_sum.x = hitted->rgb.x;
				if (color_vector_sum.y > hitted->rgb.y)
					color_vector_sum.y = hitted->rgb.y;
				if (color_vector_sum.z > hitted->rgb.z)
					color_vector_sum.z = hitted->rgb.z;
			}
			engine->img.addr[(WIN_HEIGHT - j - 1) * engine->img.line_length / 4 + (WIN_WIDTH - i)] = convert_color_vec3(color_vector_sum);

			// previous version
			// t_vec3 color_vector = get_color_vec3(ray);
			// t_vec3 color_vector = get_color(ray, engine->objects.shape);
			// engine->img.addr[(WIN_HEIGHT - 1 - j) * engine->img.line_length / 4 + (i)] = convert_color_vec3(color_vector); 
		} 
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img.ptr, 0, 0);
	mlx_loop(engine->mlx);
}
