/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:13:05 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/07 11:25:23 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "engine.h"
#include "object.h"
#include "raytrace.h"
#include "color.h"
#include "utils.h"

t_vec3	get_color(t_engine *engine, t_vec3 pixel_center)
{
	int		sampling;
	t_ray	ray;
	t_vec3	sample_pixel;
	t_vec3	color_vector_sum;
	t_shape	*hitted_shape;

	sampling = 0;
	hitted_shape = 0;
	color_vector_sum = vec3(0, 0, 0);
	ray.origin = engine->objects.camera.coord;
	while (sampling < 50)
	{
		sample_pixel = add_vec3(pixel_center, vec3((-0.5 + random_double_zerone()) * engine->display.pixel_delta[WIDTH], (-0.5 + random_double_zerone()) * engine->display.pixel_delta[HEIGHT], 0));
		ray.direction = norm_vec3(sub_vec3(sample_pixel, ray.origin));
		color_vector_sum = add_vec3(color_vector_sum, raytrace(ray, engine->objects.shape, 50, &hitted_shape));
		sampling++;
	}
	color_vector_sum = scale_vec3(0.02, color_vector_sum);
	if (hitted_shape)
	{
		color_vector_sum = add_vec3(color_vector_sum, scale_vec3(0.2, hitted_shape->rgb));
		correct_color(&color_vector_sum, hitted_shape); // 이게 맞나
	}
	return (color_vector_sum);
}