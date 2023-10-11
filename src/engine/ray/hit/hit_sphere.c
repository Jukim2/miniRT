/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:42:43 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/11 14:11:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "numft.h"
#include <math.h>

t_hit_record	hit_sphere(t_ray ray, t_shape *shape)
{
	t_hit_record	record;
	t_vec3			oc;
	double			a;
	double			b;
	double			c;
	double			d;

	init_hit_record(&record);
	oc = sub_vec3(ray.origin, shape->coord);
	a = dot_vec3(ray.direction, ray.direction);
	b = dot_vec3(oc, ray.direction);
	c = dot_vec3(oc, oc) - (shape->diameter / 2.) * (shape->diameter / 2.);
	d = b * b - a * c;
	if (d < 0)
		return (record);
	record.is_hit = TRUE;
	record.t = (-b - sqrt(d)) / a;
	record.hit_shape = shape;
	record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	record.normal = norm_vec3(sub_vec3(record.point, shape->coord));
	record.color = shape->rgb;
	record.is_front = dot_vec3(ray.direction, record.normal) > 0.;	
	return (record);
}
