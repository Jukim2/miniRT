/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:30:26 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/05 22:55:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "ray.h"
#include "object.h"
#include "parse.h"

t_vector3	get_color(t_ray ray, t_shape *shape)
{
	const double	a = 0.5 * (ray.direction.y + 1.0);
	const t_shape	*target = find_target(ray, shape);
	
	if (target)
	{
		return (get_vector3(target->rgb.x/255, target->rgb.y/255, target->rgb.z/255));	
	}
	return add_vector3(get_vector3(1 - a, 1 - a, 1 - a), get_vector3(0.5 * a, 0.7 * a, 1.0 * a));
}

t_shape	*find_target(t_ray ray, t_shape *shape)
{
	double	min_t;
	double	tmp_t;
	t_shape	*tmp;
	t_shape	*target;

	min_t = 1000000000;
	target = 0;
	while (shape)
	{
		// if shape is sphere
		// 만약에 t값이 같으면 뭘 먼저
		if (shape->type == SPHERE)
			tmp_t = hit_sphere(ray, shape->coord, shape->diameter / 2.0);
		else if (shape->type == CYLINDER)
			tmp_t = hit_cylinder(ray, *shape);
		if (tmp_t != -1 && tmp_t > 0)
		{
			if (tmp_t < min_t)
			{
				min_t = tmp_t;
				target = shape;
			}
		}
		shape = shape->next;
	}
	return (target);
}