/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:30:26 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/06 12:33:39 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "ray.h"
#include "object.h"
#include "engine.h"


#include <stdio.h>
t_vector3	random_on_hemisphere(const t_shape *shape);

// t_vector3	get_color(t_engine *engine, t_vector3 pixel_center)
// {
// 	int			sampling;
// 	t_ray		ray;
// 	t_vector3	color_vector_sum;
// 	t_vector3	sample_pixel;

// 	sampling = 0;
// 	color_vector_sum = get_vector3(0, 0, 0);
// 	// ray.origin = engine->objects.light.coord;
// 	ray.origin = get_vector3(0, 0, 0);
// 	while (sampling < 10)
// 	{
// 		sample_pixel = add_vector3(pixel_center, get_vector3((-0.5 + random_double_zerone()) * pixel_delta_x, (-0.5 + random_double_zerone()) * pixel_delta_y, 0));
// 		ray.direction = get_unit_vector3(subtract_vector3(sample_pixel, get_vector3(0, 0, 0)));
// 		color_vector_sum = add_vector3(color_vector_sum, raytrace(ray, engine->objects.shape, 50));
// 		sampling++;
// 	}
// 	return (multiple_vector3(0.1, color_vector_sum));
// }

t_vector3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted)
{
	const double	a = 0.5 * (ray.direction.y + 1.0);
	double			t;
	t_shape	*nearest_shape = find_nearest_shape(ray, shape, &t);
	
	if (depth <= 0)
		return (get_vector3(0, 0, 0));

	if (nearest_shape)
	{
		t_ray new_ray;
		t_vector3 light = subtract_vector3(get_vector3(2, 2, 1), add_vector3(ray.origin, multiple_vector3(t, ray.direction)));

		if (!(*hitted))
			*hitted = nearest_shape;
		new_ray.origin = add_vector3(ray.origin, multiple_vector3(t, ray.direction));
		if (dot_product_vector3(nearest_shape->surface_normal_vector, light) < 0)
		{
			// return (multiple_vector3(0.2, nearest_shape->rgb));
			return (get_vector3(0, 0, 0));
		}
		if (nearest_shape->material == SCATTER)
        {
            new_ray.direction = get_unit_vector3(add_vector3(nearest_shape->surface_normal_vector, random_on_hemisphere(nearest_shape)));
            if (new_ray.direction.x < 0.000001 && new_ray.direction.y < 0.000001 && new_ray.direction.z < 0.000001)
                new_ray.direction = nearest_shape->surface_normal_vector;
            return (multiple_vector3(dot_product_vector3(nearest_shape->surface_normal_vector, light) / (get_vector3_length(nearest_shape->surface_normal_vector) * get_vector3_length(light)), multiply_color_vector3(nearest_shape->rgb, raytrace(new_ray, shape, depth -1, hitted))));
        }
        else
        {
            new_ray.direction = subtract_vector3(ray.direction, multiple_vector3(2, multiple_vector3(dot_product_vector3(ray.direction, nearest_shape->surface_normal_vector), nearest_shape->surface_normal_vector)));
            return (multiply_color_vector3(nearest_shape->rgb, raytrace(new_ray, shape, depth -1, hitted)));
        }
	}
	return (get_vector3(1, 1, 1));
	return add_vector3(get_vector3(1 - a, 1 - a, 1 - a), get_vector3(0.5 * a, 0.7 * a, 1.0 * a));
}

t_vector3	random_on_hemisphere(const t_shape *shape)
{
	const t_vector3 rand_vector = get_random_vector3();

	if (dot_product_vector3(shape->surface_normal_vector, rand_vector) > 0.)
		return (rand_vector);
	else
		return (multiple_vector3(-1.0, rand_vector));
}

t_shape	*find_nearest_shape(t_ray ray, t_shape *shape, double *t)
{
	double	min_t;
	double	tmp_t;
	t_shape	*nearest_shape;

	min_t = 1000000000;
	nearest_shape = 0;
	while (shape)
	{
		// if shape is sphere
		// 만약에 t값이 같으면 뭘 먼저
		tmp_t = hit_sphere(ray, shape->coord, shape->diameter / 2.0);
		if (tmp_t != -1 && tmp_t > 0.001)
		{
			if (tmp_t < min_t)
			{	
				min_t = tmp_t;
				*t = min_t;
				nearest_shape = shape;				
			}
		}
		shape = shape->next;
	}
	if (nearest_shape)
		set_surface_normal_vector(ray, nearest_shape, min_t);
	return (nearest_shape);
}
