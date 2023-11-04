/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:08:02 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/04 17:15:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "object.h"
#include "ray.h"

t_vec3	get_reflected_direction(t_ray ray, t_hit_record record)
{
	t_vec3	direction;

	if (record.mat == SCATTER)
	{
		direction = norm_vec3(add_vec3(record.normal, \
							rand_vec3_hemisphere(record.normal)));
	}
	else
	{
		direction = sub_vec3(ray.direction, scale_vec3(2, scale_vec3(\
			dot_vec3(ray.direction, record.normal), record.normal)));
	}
	direction = norm_vec3(direction);
	if (direction.x < 0.000001 \
		&& direction.y < 0.000001 \
		&& direction.z < 0.000001)
		direction = record.normal;
	return (direction);
}

int	is_shadowed(t_shape *shape, t_vec3 point, t_vec3 light_vec, t_vec3 light)
{
	t_ray			tolight;
	t_hit_record	r;

	tolight.origin = point;
	tolight.direction = light_vec;
	r = get_hit_record(tolight, shape);
	if (!r.is_hit)
		return (0);
	else if (vec3len(sub_vec3(point, r.point)) \
			> vec3len(sub_vec3(point, light)))
		return (0);
	else
		return (1);
}
