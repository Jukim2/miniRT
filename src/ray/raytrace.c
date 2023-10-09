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

#include "vec3.h"
#include "ray.h"
#include "object.h"
#include "engine.h"
#include "utils.h"
#include "color.h"
#include "parse.h"

t_vec3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted)
{
	const double	a = 0.5 * (ray.direction.y + 1.0);
	double			t;
	t_shape			*hitted_shape = get_hit_shape(ray, shape, &t);
	
	if (depth <= 0)
		return (vec3(0, 0, 0));
	if (hitted_shape)
	{
		t_ray	reflected_ray;
		t_vec3	light;

		if (!(*hitted))
			*hitted = hitted_shape;
		reflected_ray.origin = add_vec3(ray.origin, scale_vec3(t, ray.direction));
		reflected_ray.direction = get_reflected_direction(ray, hitted_shape);
		light = norm_vec3(sub_vec3(vec3(2, 2, 1), reflected_ray.origin));
		if (is_shadowed(shape, reflected_ray, light) || dot_vec3(hitted_shape->surface_normal_vector, light) <= 0)
			return (vec3(0, 0, 0));
		return (scale_vec3(dot_vec3(hitted_shape->surface_normal_vector, light), multiply_color_vec3(hitted_shape->rgb, raytrace(reflected_ray, shape, depth -1, hitted))));
	}
	return add_vec3(vec3(1 - a, 1 - a, 1 - a), vec3(0.5 * a, 0.7 * a, 1.0 * a));
}

// 만약에 t값이 같으면 뭘 먼저
t_shape	*get_hit_shape(t_ray ray, t_shape *shape, double *t)
{
	double	min_t;
	double	curr_t;
	t_shape	*hitted_shape;

	min_t = 1000000000;
	hitted_shape = 0;
	while (shape)
	{
		if (shape->type == SPHERE)
			curr_t = hit_sphere(ray, shape->coord, shape->diameter / 2.0);
		else if (shape->type == CYLINDER)
			curr_t = hit_cylinder(ray, shape);
		else if (shape->type == PLANE)
			curr_t = hit_plane(ray, shape);
		if (curr_t != -1 && curr_t > 0.001)
		{
			if (curr_t < min_t)
			{	
				min_t = curr_t;
				*t = min_t;
				hitted_shape = shape;				
			}
		}
		shape = shape->next;
	}
	if (hitted_shape)
		set_surface_normal_vector(ray, hitted_shape, min_t);
	return (hitted_shape);
}
