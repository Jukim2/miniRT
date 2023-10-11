/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/11 14:22:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// normal : n
// center : c (plane point)
// ray origin : o
// ray direction : d
// t = ((N dot C) - (N dot O)) / (N dot D)
t_hit_record	hit_plane(t_ray ray, t_shape *shape)
{
	t_hit_record	record;
	t_vec3	o_c;
	double	n_dot_c;
	double	n_dot_d;

	init_hit_record(&record);
	o_c = sub_vec3(ray.origin, shape->coord);
	n_dot_c = dot_vec3(shape->form_vector, sub_vec3(shape->coord, ray.origin));
	n_dot_d = dot_vec3(shape->form_vector, ray.direction);
	if (n_dot_c / n_dot_d == 0)
		return (record);
	record.is_hit = TRUE;
	record.is_front = TRUE;
	record.t = n_dot_c / n_dot_d;
	record.hit_shape = shape;
	record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	record.color = shape->rgb;
	if (dot_vec3(ray.direction, shape->form_vector) > 0.)
		record.normal = shape->form_vector;
	else
		record.normal = invert_vec3(shape->form_vector);
	return (record);
}
