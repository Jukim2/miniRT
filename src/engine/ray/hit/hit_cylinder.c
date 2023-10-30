/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:36:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 16:22:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "numft.h"
#include <math.h>

static double		get_minimum_root(double a, double b, double c);
static t_hit_record	hit_cylinder_base(t_ray ray, t_shape *shape);
static t_hit_record	hit_cylinder_side(t_ray ray, t_shape *shape);

t_hit_record	hit_cylinder(t_ray ray, t_shape *shape)
{
	t_hit_record	side;
	t_hit_record	base;
	
	base = hit_cylinder_base(ray, shape);
	side = hit_cylinder_side(ray, shape);
	if (side.is_hit && base.is_hit)
	{
		if (doublecmp(side.t, base.t) <= 0)
			return (side);
		else
			return (base);
	}
	else if (side.is_hit)
		return (side);
	else if (base.is_hit)
		return (base);
	else
		return (base);
}


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

static t_hit_record	hit_cylinder_side(t_ray ray, t_shape *shape)
{
	t_hit_record	record;
	double			a;
	double			b;
	double			c;

	init_hit_record(&record);
	t_vec3	proj = proj_vec3_to_plane(ray.direction, shape->orientation);
	t_vec3	temp = sub_vec3(ray.origin, add_vec3(shape->coord, scale_vec3(dot_vec3(sub_vec3(ray.origin, shape->coord), shape->orientation), shape->orientation)));
	a = dot_vec3(proj, proj);
	b = dot_vec3(temp, proj);
	c = dot_vec3(temp, temp) - shape->radius * shape->radius;
	if (doublecmp((b * b - a * c), 0.) <= 0)
		return (record);
	else if (doublecmp((-b + sqrt(b * b - a * c)) / a, 0.) < 0)
		return (record);
	// record.t = get_minimum_root(a, b, c);
	// record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	// if (vec3len(sub_vec3(record.point, shape->coord)) * vec3len(sub_vec3(record.point, shape->coord)) \
	// 	- (shape->diameter / 2.) * (shape->diameter / 2.) > (shape->height / 2) * (shape->height / 2))
	// 	return (record);
	double t1 = get_minimum_root(a, b, c);
	t_vec3 cp = add_vec3(ray.origin, scale_vec3(t1, ray.direction));
	if (vec3len(sub_vec3(cp, shape->coord)) * vec3len(sub_vec3(cp, shape->coord)) - shape->radius * shape->radius > (shape->height / 2) * (shape->height / 2))
		return (record);
	record.is_hit = TRUE;
	record.t = get_minimum_root(a, b, c);
	record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	record.normal = proj_vec3_to_plane(sub_vec3(record.point, shape->coord), shape->orientation);
	record.is_front = dot_vec3(ray.direction, record.normal) > 0.;
	record.rgb = shape->rgb;
	record.mat = shape->material;
	return (record);
}

static t_hit_record	hit_cylinder_base(t_ray ray, t_shape *shape)
{
	t_shape			base;
	t_hit_record	up;
	t_hit_record	down;

	base.next = 0;
	base.type = CIRCLE;
	base.face = 1;
	base.material = shape->material;
	base.radius = shape->radius;
	base.height = 0;
	base.coord = add_vec3(shape->coord, scale_vec3(shape->height / 2, shape->orientation));
	base.orientation = shape->orientation;
	base.rgb = shape->rgb;
	up = hit_circle(ray, &base);
	base.coord = add_vec3(shape->coord, scale_vec3(-shape->height / 2, shape->orientation));
	base.orientation = invert_vec3(shape->orientation);
	down = hit_circle(ray, &base);
	if (up.is_hit)
		return (up);
	else if (down.is_hit)
		return (down);
	else
	{
		init_hit_record(&down);
		return (down);
	}
}