/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:36:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/07 12:03:33 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "raytrace.h"
#include "vec3.h"
#include <math.h>

#include <stdio.h>

double	hit_cylinder(t_ray ray, t_shape shape)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;

	t_vec3	proj = sub_vec3(ray.direction, scale_vec3(dot_vec3(ray.direction, shape.surface_normal_vector), shape.surface_normal_vector));
	t_vec3	temp = sub_vec3(ray.origin, add_vec3(shape.coord, scale_vec3(dot_vec3(sub_vec3(ray.origin, shape.coord), shape.surface_normal_vector), shape.surface_normal_vector)));
	a = dot_vec3(proj, proj);
	b = dot_vec3(temp, proj);
	c = dot_vec3(temp, temp) - (shape.diameter / 2.0) * (shape.diameter / 2.0);
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant)) / a);
}
