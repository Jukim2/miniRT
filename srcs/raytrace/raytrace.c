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
#include "raytrace.h"
#include "object.h"
#include "engine.h"
#include "utils.h"
#include "color.h"
#include "hit.h"

#include <math.h>

t_vec3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted)
{
	const double	a = 0.5 * (ray.direction.y + 1.0);
	double			t;
	t_shape			*hitted_shape = find_hitted_shape(ray, shape, &t);
	
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
	return (vec3(1, 1, 1));
}

t_shape	*find_hitted_shape(t_ray ray, t_shape *shape, double *t)
{
	double	min_t;
	double	tmp_t;
	t_shape	*hitted_shape;

	min_t = 1000000000;
	hitted_shape = 0;
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
				hitted_shape = shape;				
			}
		}
		shape = shape->next;
	}
	if (hitted_shape)
	{
		set_surface_normal_vector(ray, hitted_shape, min_t);
		// set color by coordinate
		t_vec3 hitpoint = add_vec3(ray.origin, scale_vec3(min_t, ray.direction));
		// hitted_shape->rgb = vec3(0, 1, 0);
		t_vec3 e1 = vec3(0, 0, 1);
		t_vec3 e2 = vec3(0, 1, 0);
		t_vec3 point = sub_vec3(hitpoint, hitted_shape->coord);
		t_vec3 point_no_y = hitpoint;
		t_vec3 point_no_z = hitpoint;
		point_no_y.y = 0;
		point_no_y = norm_vec3(point_no_y);
		point_no_z.z = 0;
		point_no_z = norm_vec3(point_no_z);
		double vert_angle = acos(dot_vec3(point_no_z, e2));
		double hort_angle = acos(dot_vec3(point_no_y, e1));
		// hitted_shape->rgb = earth
		
	}
	return (hitted_shape);
}
