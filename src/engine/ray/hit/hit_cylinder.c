/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:36:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/11 14:23:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "numft.h"
#include <math.h>

#include <stdio.h>

// t_hit_record	hit_cylinder(t_ray ray, t_shape *shape)
// {
// 	t_hit_record	record;
// 	double			a;
// 	double			b;
// 	double			c;
// 	double			d;

// 	init_hit_record(&record);
// 	t_vec3	proj = sub_vec3(ray.direction, scale_vec3(dot_vec3(ray.direction, shape->form_vector), shape->form_vector));
// 	t_vec3	temp = sub_vec3(ray.origin, add_vec3(shape->coord, scale_vec3(dot_vec3(sub_vec3(ray.origin, shape->coord), shape->form_vector), shape->form_vector)));
// 	a = dot_vec3(proj, proj);
// 	b = dot_vec3(temp, proj);
// 	c = dot_vec3(temp, temp) - (shape->diameter / 2.0) * (shape->diameter / 2.0);
// 	d = b * b - a * c;
// 	if (d < 0)
// 	{	
// 		t_shape	up;
// 		t_shape	down;

		

// 		return (-1);
// 	}
// 	else
// 	{
// 		double t1 = (-b - sqrt(d)) / a;
// 		double t2 = (-b + sqrt(d)) / a;
// 		t_vec3 contact_point1 = add_vec3(ray.origin, scale_vec3(t1, ray.direction));
// 		t_vec3 contact_point2 = add_vec3(ray.origin, scale_vec3(t2, ray.direction));

// 		int a = vec3len(sub_vec3(contact_point1, shape->coord)) * vec3len(sub_vec3(contact_point1, shape->coord)) - (shape->diameter / 2.) *(shape->diameter / 2.) <= (shape->height / 2)* (shape->height / 2);
// 		int b = vec3len(sub_vec3(contact_point2, shape->coord)) * vec3len(sub_vec3(contact_point2, shape->coord)) - (shape->diameter / 2.) *(shape->diameter / 2.) <= (shape->height / 2) * (shape->height / 2);
		
// 		if (a == 0 && b == 0)
// 			return (-1);
// 		else if (a + b == 1)
// 		{
// 			t_shape upper_plane;
// 			upper_plane.form_vector = shape->form_vector;
// 			upper_plane.coord = add_vec3(shape->coord, scale_vec3(shape->height / 2., shape->form_vector));

// 			t_shape lower_plane;
// 			lower_plane.form_vector = invert_vec3(shape->form_vector);
// 			lower_plane.coord = add_vec3(shape->coord, scale_vec3(shape->height /2., lower_plane.form_vector));

// 			double tup = hit_plane(ray, &upper_plane);
// 			double t_low = hit_plane(ray, &lower_plane);
// 			if (tup < t2)
// 			{
// 				shape->surface_normal_vector = shape->form_vector;
// 				return (tup);
// 			}
// 			return (t2);
// 		}
// 		else
// 			return (t1);
// 	}
// }
