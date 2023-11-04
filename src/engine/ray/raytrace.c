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
#include "color.h"
#include "parse.h"

t_vec3	raytrace(t_ray ray, t_objects *objs, int depth)
{
	t_hit_record	record;
	t_ray			reflected_ray;
	t_vec3			light;

	if (depth <= 0)
		return (vec3(0, 0, 0));
	record = get_hit_record(ray, objs->shape);
	if (record.is_hit)
	{
		reflected_ray.origin = record.point;
		reflected_ray.direction = get_reflected_direction(ray, record);
		light = norm_vec3(sub_vec3(objs->light.coord, record.point));
		if (is_shadowed(objs->shape, record.point, light, objs->light.coord) \
			|| dot_vec3(record.normal, light) <= 0)
			return (vec3(0, 0, 0));
		return (scale_vec3(dot_vec3(record.normal, light), record.rgb));
	}
	return (vec3(0, 0, 0));
}
