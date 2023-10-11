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

#include "numft.h"
#include "ray.h"
#include "object.h"
#include "engine.h"
#include "color.h"
#include "parse.h"

t_vec3	raytrace(t_ray ray, t_shape *shape, int depth, t_shape **hitted)
{
	t_hit_record	record;
	t_ray			reflected_ray;
	t_vec3			light;
	
	if (depth <= 0)
		return (vec3(0, 0, 0));
	record = get_hit_record(ray, shape);
	if (record.hit_shape)
	{
		if (!(*hitted))
			*hitted = record.hit_shape;
		reflected_ray.origin = record.point;
		reflected_ray.direction = get_reflected_direction(ray, record.hit_shape);
		light = norm_vec3(sub_vec3(vec3(2, 2, 1), reflected_ray.origin));
		if (is_shadowed(shape, reflected_ray, light) || dot_vec3(record.normal, light) <= 0)
			return (vec3(0, 0, 0));
		return (scale_vec3(dot_vec3(record.normal, light), multiply_color_vec3(record.hit_shape->rgb, raytrace(reflected_ray, shape, depth -1, hitted))));
	}
	return (vec3(1, 1, 1));
}
