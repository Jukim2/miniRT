/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:42:43 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/24 17:27:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "numft.h"
#include <math.h>

static double	get_minimum_t(double a, double b, double c)
{
	double	t1;
	double	t2;

	t1 = (-b + sqrt(b * b - a * c)) / a;
	t2 = (-b - sqrt(b * b - a * c)) / a;
	if (compare_double(t2, 0.) <= 0)
		return t1;
	else
		return t2;
}

t_hit_record	hit_sphere(t_ray ray, t_shape *shape)
{
	t_hit_record	record;
	t_vec3			oc;
	double			a;
	double			b;
	double			c;

	init_hit_record(&record);
	oc = sub_vec3(ray.origin, shape->coord);
	a = dot_vec3(ray.direction, ray.direction);
	b = dot_vec3(oc, ray.direction);
	c = dot_vec3(oc, oc) - (shape->diameter / 2.) * (shape->diameter / 2.);
	if (compare_double((b * b - a * c), 0.) <= 0)
		return (record);
	else if (compare_double((-b + sqrt(b * b - a * c)) / a, 0.) < 0)
		return (record);
	record.is_hit = TRUE;
	record.t = get_minimum_t(a, b, c);
	record.hit_shape = shape;
	record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	record.normal = norm_vec3(sub_vec3(record.point, shape->coord));
	record.color = shape->rgb;
	record.is_front = dot_vec3(ray.direction, record.normal) > 0.;	
	return (record);
}
