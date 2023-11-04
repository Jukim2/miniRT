/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:32:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_hit_record	hit_plane(t_ray ray, t_shape *shape)
{
	t_hit_record	hr;
	double			t;

	init_hit_record(&hr);
	if (dot_vec3(shape->orient, ray.direction) == 0)
		return (hr);
	t = dot_vec3(shape->orient, sub_vec3(shape->coord, ray.origin)) \
		/ dot_vec3(shape->orient, ray.direction);
	if (doublecmp(t, 0.) <= 0)
		return (hr);
	hr.is_hit = TRUE;
	hr.t = t;
	hr.point = add_vec3(ray.origin, scale_vec3(hr.t, ray.direction));
	if (dot_vec3(ray.direction, shape->orient) > 0.)
		hr.normal = invert_vec3(shape->orient);
	else
		hr.normal = shape->orient;
	hr.rgb = shape->rgb;
	hr.mat = shape->mat;
	return (hr);
}
