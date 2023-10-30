/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:42:43 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 16:22:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "numft.h"
#include <math.h>

static double	get_minimum_root(double a, double b, double c)
{
	double	t1;
	double	t2;

	t1 = (-b + sqrt(b * b - a * c)) / a;
	t2 = (-b - sqrt(b * b - a * c)) / a;
	if (doublecmp(t2, 0.) <= 0)
		return t1;
	else
		return t2;
}

t_hit_record	hit_sphere(t_ray ray, t_shape *shape)
{
	t_hit_record	hr;
	t_vec3			oc;
	double			a;
	double			b;
	double			c;

	init_hit_record(&hr);
	oc = sub_vec3(ray.origin, shape->coord);
	a = dot_vec3(ray.direction, ray.direction);
	b = dot_vec3(oc, ray.direction);
	c = dot_vec3(oc, oc) - shape->radius * shape->radius;
	if (doublecmp((b * b - a * c), 0.) <= 0)
		return (hr);
	else if (doublecmp((-b + sqrt(b * b - a * c)) / a, 0.) < 0)
		return (hr);
	hr.is_hit = TRUE;
	hr.t = get_minimum_root(a, b, c);
	hr.point = add_vec3(ray.origin, scale_vec3(hr.t, ray.direction));
	hr.normal = norm_vec3(sub_vec3(hr.point, shape->coord));
	hr.is_front = dot_vec3(ray.direction, hr.normal) > 0.;	
	hr.rgb = shape->rgb;
	hr.mat = shape->material;
	return (hr);
}
