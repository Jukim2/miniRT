/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_vector3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 19:34:47 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "ray.h"

t_vector3	get_color_vector3(t_ray ray)
{
	t_vector3	color;
	t_vector3	center; // sphere
	double		radius;
	double		t;


	center = get_vector3(0, 0, -1);
	radius = 0.5;
	t = hit_sphere(ray, center, radius);
	if (t > 0.0)
	{
		t_vector3 a = add_vector3(ray.origin, multiple_vector3(-t, ray.direction));
		t_vector3 one = get_vector3(1, 1, 1);
		return multiple_vector3(0.5, add_vector3(a, one));
	}
	double a = 0.5 * (ray.direction.y + 1.0);
	color = add_vector3(get_vector3(1 - a, 1 - a, 1 - a), get_vector3(0.5 * a, 0.7 * a, 1.0 * a));
	return (color);
}