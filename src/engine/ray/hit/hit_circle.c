/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:56:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/27 00:23:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "ray.h"

#include <stdio.h>

t_hit_record	hit_circle(t_ray ray, t_vec3 c, t_vec3 n, double r, t_vec3 rgb)
{
	t_shape			circle;
	t_hit_record	record;
	t_vec3			inter_point;

	circle.next = 0;
	circle.type = PLANE;
	circle.face = 1;
	circle.material = 0;
	circle.diameter = 2 * r;
	circle.height = 0;
	circle.coord = c;
	circle.form_vector = n;
	circle.rgb = rgb;
	record = hit_plane(ray, &circle);
	if (!record.is_hit)
	{
		return (record);
	}
	else
	{
		inter_point = add_vec3(ray.origin, scale_vec3(record.t, ray.direction));
		if (vec3len(sub_vec3(c, inter_point)) >= r)
		{
			record.is_hit = FALSE;
			return (record);
		}
		else
		{
			// printf("t : %f \n", record.t);
			record.color = rgb;
			return (record);
		}
	}
}
