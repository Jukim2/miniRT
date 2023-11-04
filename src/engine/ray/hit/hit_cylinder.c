/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:36:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:40:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "numft.h"
#include <math.h>

static double		get_minimum_root(double a, double b, double c);
static t_vec3		get_tmp_vec3(t_vec3 origin, t_vec3 coord, t_vec3 orient);
static t_hit_record	hit_cylinder_base(t_ray ray, t_shape *shp);
static t_hit_record	hit_cylinder_side(t_ray ray, t_shape *shp);

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
		return (t1);
	else
		return (t2);
}

static t_vec3	get_tmp_vec3(t_vec3 origin, t_vec3 coord, t_vec3 orient)
{
	t_vec3	tmp;

	tmp = sub_vec3(origin, add_vec3(coord, scale_vec3(dot_vec3(\
			sub_vec3(origin, coord), orient), orient)));
	return (tmp);
}

static t_hit_record	hit_cylinder_side(t_ray ray, t_shape *shp)
{
	t_hit_record	r;
	const t_vec3	p = proj_vec3(ray.direction, shp->orient);
	const t_vec3	tmp = get_tmp_vec3(ray.origin, shp->coord, shp->orient);
	double			d;

	init_hit_record(&r);
	d = pow(dot_vec3(tmp, p), 2) - \
		dot_vec3(p, p) * (dot_vec3(tmp, tmp) - pow(shp->radius, 2));
	if (doublecmp(d, 0.) <= 0 || dot_vec3(p, p) == 0)
		return (r);
	else if (doublecmp((-dot_vec3(tmp, p) + sqrt(d)) / dot_vec3(p, p), 0.) < 0)
		return (r);
	r.t = get_minimum_root(dot_vec3(p, p), dot_vec3(tmp, p), \
			dot_vec3(tmp, tmp) - pow(shp->radius, 2));
	r.point = add_vec3(ray.origin, scale_vec3(r.t, ray.direction));
	if (doublecmp(pow(vec3len(sub_vec3(r.point, shp->coord)), 2) \
		- pow(shp->radius, 2.), pow(shp->height / 2., 2)) > 0)
		return (r);
	r.is_hit = TRUE;
	r.normal = norm_vec3(proj_vec3(sub_vec3(r.point, shp->coord), shp->orient));
	if (dot_vec3(ray.direction, r.normal) > 0.)
		r.normal = invert_vec3(r.normal);
	r.rgb = shp->rgb;
	r.mat = shp->mat;
	return (r);
}

static t_hit_record	hit_cylinder_base(t_ray ray, t_shape *shp)
{
	t_shape			b;
	t_hit_record	up;
	t_hit_record	down;

	b.next = 0;
	b.type = CIRCLE;
	b.face = 1;
	b.mat = shp->mat;
	b.radius = shp->radius;
	b.height = 0;
	b.coord = add_vec3(shp->coord, scale_vec3(shp->height / 2, shp->orient));
	b.orient = shp->orient;
	b.rgb = shp->rgb;
	up = hit_circle(ray, &b);
	b.coord = add_vec3(shp->coord, scale_vec3(-shp->height / 2, shp->orient));
	b.orient = invert_vec3(shp->orient);
	down = hit_circle(ray, &b);
	if (up.is_hit)
		return (up);
	else if (down.is_hit)
		return (down);
	init_hit_record(&down);
	return (down);
}
