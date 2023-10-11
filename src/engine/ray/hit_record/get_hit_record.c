/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:50:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/11 01:28:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "ray.h"

t_hit_record	get_hit_record(t_ray ray, t_shape *shape)
{
	t_hit_record	record;
	double			t;

	init_hit_record(&record);
	while (shape)
	{
		if (shape->type == SPHERE)
			t = hit_sphere(ray, shape->coord, shape->diameter / 2.0); // hit function returns hit record
		else if (shape->type == CYLINDER)
			t = hit_cylinder(ray, shape);
		else if (shape->type == PLANE)
			t = hit_plane(ray, shape);
		if (t != -1 && t > 0.001)
		{
			if (t < record.t)
			{	
				record.is_hit = 1;
				record.t = t;
				record.hit_shape = shape;		
			}
		}
		shape = shape->next;
	}
	if (record.is_hit)
		set_surface_normal_vector(ray, record.hit_shape, record.t);
	return (record);
}
