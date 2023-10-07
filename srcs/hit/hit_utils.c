/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:54 by kjs               #+#    #+#             */
/*   Updated: 2023/10/07 12:03:24 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace.h"
#include "vec3.h"
#include "object.h"
#include <math.h>

void	set_surface_normal_vector(t_ray ray, t_shape *shape, double t)
{
	const t_vec3 contact_point = add_vec3(ray.origin, scale_vec3(t, ray.direction));
	const t_vec3 surface_normal_vector = norm_vec3(sub_vec3(contact_point, shape->coord));

	if (dot_vec3(ray.direction, surface_normal_vector) > 0.0)
	{
		shape->surface_normal_vector = scale_vec3(-1.0, surface_normal_vector);
		shape->face = BACK;
	}
	else
	{
		shape->surface_normal_vector = surface_normal_vector;
		shape->face = FRONT;
	}
}

