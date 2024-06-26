/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:50:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/04 17:31:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "ray.h"

t_hit_record	get_hit_record(t_ray ray, t_shape *shape)
{
	t_hit_record	nearest;
	t_hit_record	curr;

	init_hit_record(&nearest);
	while (shape)
	{
		if (shape->type == SPHERE)
			curr = hit_sphere(ray, shape);
		else if (shape->type == CYLINDER)
			curr = hit_cylinder(ray, shape);
		else if (shape->type == PLANE)
			curr = hit_plane(ray, shape);
		if (curr.is_hit && doublecmp(curr.t, 0) > 0)
		{
			if (curr.t < nearest.t)
				nearest = curr;
		}
		shape = shape->next;
	}
	return (nearest);
}
