/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:08:02 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/07 13:14:36 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "object.h"
#include "raytrace.h"

t_vec3	random_on_hemisphere(const t_shape *shape)
{
	const t_vec3 rand_vector = rand_vec3();

	if (dot_vec3(shape->surface_normal_vector, rand_vector) > 0.)
		return (rand_vector);
	else
		return (scale_vec3(-1.0, rand_vector));
}

t_vec3	get_reflected_direction(t_ray ray, t_shape *hitted_shape)
{
	t_vec3	direction;
	if (hitted_shape->material == SCATTER)
	{
		direction = add_vec3(hitted_shape->surface_normal_vector, random_on_hemisphere(hitted_shape));
	}
	else
	{
		direction = sub_vec3(ray.direction, scale_vec3(2, scale_vec3(dot_vec3(ray.direction, hitted_shape->surface_normal_vector), hitted_shape->surface_normal_vector)));
	}
	direction = norm_vec3(direction);
	if (direction.x < 0.000001 && direction.y < 0.000001 && direction.z < 0.000001)
		direction = hitted_shape->surface_normal_vector;
	return (direction);
}

int	is_shadowed(t_shape *shape, t_ray reflected_ray, t_vec3 light)
{
	double	t;
	t_ray	tolight;

	tolight.origin = reflected_ray.origin;
	tolight.direction = light;
	return (find_hitted_shape(tolight, shape, &t) != 0);
}