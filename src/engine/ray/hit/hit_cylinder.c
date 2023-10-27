/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:36:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/27 17:44:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "numft.h"
#include <math.h>

#include <stdio.h>

static double	get_minimum_root(double a, double b, double c)
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

static t_hit_record	hit_cylinder_side(t_ray ray, t_shape *shape)
{
	t_hit_record	record;
	double			a;
	double			b;
	double			c;

	init_hit_record(&record);
	t_vec3	proj = proj_vec3_to_plane(ray.direction, shape->form_vector);
	t_vec3	temp = sub_vec3(ray.origin, add_vec3(shape->coord, scale_vec3(dot_vec3(sub_vec3(ray.origin, shape->coord), shape->form_vector), shape->form_vector)));
	a = dot_vec3(proj, proj);
	b = dot_vec3(temp, proj);
	c = dot_vec3(temp, temp) - (shape->diameter / 2.0) * (shape->diameter / 2.0);
	if (compare_double((b * b - a * c), 0.) <= 0)
		return (record);
	else if (compare_double((-b + sqrt(b * b - a * c)) / a, 0.) < 0)
		return (record);
	double t1 = get_minimum_root(a, b, c);
	t_vec3 cp = add_vec3(ray.origin, scale_vec3(t1, ray.direction));
	if (vec3len(sub_vec3(cp, shape->coord)) * vec3len(sub_vec3(cp, shape->coord)) - (shape->diameter / 2.) * (shape->diameter / 2.) > (shape->height / 2) * (shape->height / 2))
		return (record);
	record.is_hit = TRUE;
	record.t = get_minimum_root(a, b, c);
	record.hit_shape = shape;
	record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	record.normal = proj_vec3_to_plane(sub_vec3(record.point, shape->coord), shape->form_vector);
	record.color = shape->rgb;
	record.is_front = dot_vec3(ray.direction, record.normal) > 0.;
	return (record);
}

double	min_double2(double a, double b)
{
	if (compare_double(a, b) <= 0)
		return (0);
	else
		return (1);
}

double	min_double3(double a, double b, double c)
{
	double	min;

	min = min_double2(a, b);
	min = min_double2(min, c);
	return (min);
}

static int	min_idx_double3(double a, double b, double c)
{
	if (compare_double(a, b) <= 0 && compare_double(a, c) <= 0)
		return (a);
	else if (compare_double(b, a) <= 0 && compare_double(b, c) <= 0)
		return (b);
	else
		return (c);
}

t_hit_record	hit_cylinder_base(t_ray ray, t_shape *shape)
{
	// t_hit_record	record;
	t_hit_record	up;
	t_hit_record	down;

	// init_hit_record(&record);
	up = hit_circle(ray, \
					add_vec3(shape->coord, scale_vec3(shape->height / 2, shape->form_vector)), \
					shape->form_vector, \
					shape->diameter / 2, \
					shape->rgb);
	down = hit_circle(ray, \
		add_vec3(shape->coord, scale_vec3(-shape->height / 2, shape->form_vector)), \
		invert_vec3(shape->form_vector), \
		shape->diameter / 2, \
		shape->rgb);
	if (up.is_hit)
		return (up);
	else
		return (down);
}

t_hit_record	hit_cylinder(t_ray ray, t_shape *shape)
{
	t_hit_record	side;
	t_hit_record	base;
	
	side = hit_cylinder_side(ray, shape);
	base = hit_cylinder_base(ray, shape);
	if (side.is_hit && base.is_hit)
	{
		if (compare_double(side.t, base.t) <= 0)
			return (side);
		else
			return (base);
	}
	else if (side.is_hit)
		return (side);
	else if (base.is_hit)
		return (base);
	else
		return (side);
}