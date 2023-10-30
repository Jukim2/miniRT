/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 13:55:21 by gyoon            ###   ########.fr       */
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
	t_vec3			o_c;
	double			t;

	init_hit_record(&record);
	o_c = sub_vec3(ray.origin, shape->coord);
	t = dot_vec3(shape->form_vector, sub_vec3(shape->coord, ray.origin)) \
		/ dot_vec3(shape->form_vector, ray.direction);
	if (compare_double(t, 0.) <= 0)
		return (record);
	record.is_hit = TRUE;
	record.is_front = TRUE;
	record.t = t;
	record.point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
	record.rgb = shape->rgb;
	if (dot_vec3(ray.direction, shape->form_vector) > 0.)
		record.normal = shape->form_vector;
	else
		record.normal = invert_vec3(shape->form_vector);
	return (record);
}
