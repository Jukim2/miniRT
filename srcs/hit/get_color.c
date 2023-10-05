/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:30:26 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/05 20:39:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "ray.h"
#include "object.h"


#include <stdio.h>
t_vector3	random_on_hemisphere(const t_shape *shape);

t_vector3	get_color(t_ray ray, t_shape *shape, int depth)
{
	const double	a = 0.5 * (ray.direction.y + 1.0);
	double			t;
	const t_shape	*nearest_shape = find_nearest_shape(ray, shape, &t);
	
	if (depth <= 0)
		return (get_vector3(0, 0, 0));

	if (nearest_shape)
	{
		t_ray new_ray;

		new_ray.origin = add_vector3(ray.origin, multiple_vector3(t, ray.direction));
		new_ray.direction = add_vector3(nearest_shape->surface_normal_vector, random_on_hemisphere(nearest_shape));
		return (multiple_vector3(0.5, get_color(new_ray, shape, depth - 1)));
	}	
	return add_vector3(get_vector3(1 - a, 1 - a, 1 - a), get_vector3(0.5 * a, 0.7 * a, 1.0 * a));
}

t_vector3	random_on_hemisphere(const t_shape *shape)
{
	const t_vector3 rand_vector = get_random_vector3();

	if (dot_product_vector3(shape->surface_normal_vector, rand_vector) > 0.)
		return (rand_vector);
	else
		return (multiple_vector3(-1.0, rand_vector));
}

t_shape	*find_nearest_shape(t_ray ray, t_shape *shape, double *t)
{
	double	min_t;
	double	tmp_t;
	t_shape	*nearest_shape;

	min_t = 1000000000;
	nearest_shape = 0;
	while (shape)
	{
		// if shape is sphere
		// 만약에 t값이 같으면 뭘 먼저
		tmp_t = hit_sphere(ray, shape->coord, shape->diameter / 2.0);
		if (tmp_t != -1 && tmp_t > 0.001)
		{
			if (tmp_t < min_t)
			{	
				min_t = tmp_t;
				*t = min_t;
				nearest_shape = shape;				
			}
		}
		shape = shape->next;
	}
	if (nearest_shape)
		set_surface_normal_vector(ray, nearest_shape, min_t);
	return (nearest_shape);
}
