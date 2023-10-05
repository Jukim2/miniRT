/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:36:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 22:55:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"
#include "vector3.h"
#include <math.h>

#include <stdio.h>
double	hit_cylinder(t_ray ray, t_shape shape)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;

	t_vector3	proj = subtract_vector3(ray.direction, multiple_vector3(dot_product_vector3(ray.direction, shape.normal_vector), shape.normal_vector));
	t_vector3	temp = subtract_vector3(ray.origin, add_vector3(shape.coord, multiple_vector3(dot_product_vector3(subtract_vector3(ray.origin, shape.coord), shape.normal_vector), shape.normal_vector)));
	a = dot_product_vector3(proj, proj);
	b = dot_product_vector3(temp, proj);
	c = dot_product_vector3(temp, temp) - (shape.diameter / 2.0) * (shape.diameter / 2.0);
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant)) / a);
}
