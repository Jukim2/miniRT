/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:08:02 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 02:11:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

int	is_shadowed(t_shape *shape, t_vec3 point, t_vec3 tolight, \
				t_vec3 light_coord)
{
	t_ray			point_to_light;
	t_hit_record	r;

	point_to_light.origin = point;
	point_to_light.direction = tolight;
	r = get_hit_record(point_to_light, shape);
	if (!r.is_hit)
		return (0);
	else if (vec3len(sub_vec3(point, r.point)) \
			> vec3len(sub_vec3(point, light_coord)))
		return (0);
	else
		return (1);
}
