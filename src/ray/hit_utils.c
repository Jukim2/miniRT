/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:54 by kjs               #+#    #+#             */
/*   Updated: 2023/10/09 15:51:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"
#include "object.h"
#include "parse.h"
#include <math.h>

void	set_surface_normal_vector(t_ray ray, t_shape *shape, double t)
{
	if (shape->type == PLANE)
	{
		shape->surface_normal_vector = vec3(-shape->form_vector.x, -shape->form_vector.y, -shape->form_vector.z);
		return ;
	}
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

	// else if (shape->type == CYLINDER)
	// {
	// 	const t_vec3 contact_point = add_vec3(ray.origin, scale_vec3(t, ray.direction));

	// 	if (vec3len(sub_vec3(contact_point, shape->coord)) * vec3len(sub_vec3(contact_point, shape->coord)) - (shape->diameter / 2) *(shape->diameter / 2) > shape->height * shape->height)
	// 	{
	// 		shape->surface_normal_vector = vec3(0, 0, 0);
	// 	}
	// 	else
	// 	{
	// 		const t_vec3 surface_normal_vector = norm_vec3(sub_vec3(contact_point, shape->coord));
	// 		shape->surface_normal_vector = surface_normal_vector;

	// 	}


		
	// }
}

