/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 14:59:11 by gyoon            ###   ########.fr       */
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
	t_hit_record	hr;
	t_vec3			o_c;
	double			t;

	init_hit_record(&hr);
	o_c = sub_vec3(ray.origin, shape->coord);
	t = dot_vec3(shape->form_vector, sub_vec3(shape->coord, ray.origin)) \
		/ dot_vec3(shape->form_vector, ray.direction);
	if (doublecmp(t, 0.) <= 0)
		return (hr);
	hr.is_hit = TRUE;
	hr.t = t;
	hr.point = add_vec3(ray.origin, scale_vec3(hr.t, ray.direction));
	if (dot_vec3(ray.direction, shape->form_vector) > 0.)
		hr.normal = shape->form_vector;
	else
		hr.normal = invert_vec3(shape->form_vector);
	hr.is_front = TRUE;
	hr.rgb = shape->rgb;
	hr.mat = shape->material;
	return (hr);
}
