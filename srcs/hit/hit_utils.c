/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:54 by kjs               #+#    #+#             */
/*   Updated: 2023/10/05 14:04:15 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector3.h"
#include "object.h"
#include <math.h>

#include <stdio.h>
void	set_surface_normal_vector(t_ray ray, t_shape *shape, double t)
{
	const t_vector3 contact_point = add_vector3(ray.origin, multiple_vector3(t, ray.direction));
	const t_vector3 surface_normal_vector = get_unit_vector3(subtract_vector3(contact_point, shape->coord));

	shape->surface_normal_vector = surface_normal_vector;
	// if (dot_product_vector3(ray.direction, surface_normal_vector) > 0.0)
	// {
	// 	shape->surface_normal_vector = multiple_vector3(-1.0, surface_normal_vector);
	// 	shape->face = BACK;
	// }
	// else
	// {
	// 	shape->surface_normal_vector = surface_normal_vector;
	// 	shape->face = FRONT;
	// }
}

