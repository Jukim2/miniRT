/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:56:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 15:00:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "ray.h"

#include <stdio.h>

t_hit_record	hit_circle(t_ray ray, t_shape *shape)
{
	t_hit_record	hr;

	hr = hit_plane(ray, shape);
	if (!hr.is_hit)
		return (hr);
	else if (vec3len(sub_vec3(shape->coord, hr.point)) <= shape->diameter / 2)
		return (hr);
	else
	{
		hr.is_hit = FALSE;
		return (hr);
	}
}
