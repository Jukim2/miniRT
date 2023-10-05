/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:38:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 20:48:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "vector3.h"
#include <math.h>

#include <stdio.h>

/* TODO: error handling when fov == 0 or 180 */
/* TODO: handle window ratio */

void	execute_engine(t_engine *engine)
{
	t_vector3	pixel_center;
	t_ray		ray;

	// end quaternion
	
	ray.origin = engine->objects.camera.coord;
	for (int i = 0; i < WIN_WIDTH; i++)
	{
		for (int j = 0; j < WIN_HEIGHT; j++)
		{
			pixel_center = add_vector3(engine->display.top_left_pixel, \
										get_vector3(i * engine->display.pixel_delta[WIDTH], j * engine->display.pixel_delta[HEIGHT], 0));
			ray.direction = pixel_center; // must be rotated;

			/* add q */
			t_vector3 c = cross_product_vector3(get_vector3(0, 0, -1), engine->objects.camera.forward_vector);
			c = get_unit_vector3(c);

			double cosine = dot_product_vector3(get_vector3(0, 0, -1), engine->objects.camera.forward_vector);
			double s_half = sqrt((1.0 - cosine) / 2.0);
			double c_half = sqrt((1.0 + cosine) / 2.0);
			
			// q = cos(θ/2) + (x * sin(θ/2), y * sin(θ/2), z * sin(θ/2))
			t_quaternion q = get_quaternion(c_half, c.x * s_half, c.y * s_half, c.z * s_half);
			q = normalize_quaternion(q);

			t_quaternion a = get_quaternion(0, ray.direction.x, ray.direction.y, ray.direction.z);
			// t_quaternion rotated = q * a * q-1;
			t_quaternion temp = product_quaternion(q, a);
			t_quaternion conjugate = get_conjugate_quaternion(q);
			t_quaternion rotated = product_quaternion(temp, conjugate);
			ray.direction = get_vector3(rotated.v.x, rotated.v.y, rotated.v.z);

			/* end q */
			// ray.direction = get_unit_vector3(ray.direction); // get unit_vector
			// t_vector3 color_vector = get_color_vector3(ray);

			t_vector3 color_vector = get_color(ray, engine->objects.shape);
			engine->img.addr[(WIN_HEIGHT - 1 - j) * engine->img.line_length / 4 + (i)] = convert_color_vector3(color_vector); 
		} 
	}
	mlx_put_image_to_window(engine->mlx, engine->win, engine->img.ptr, 0, 0);
	mlx_loop(engine->mlx);
}
