/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:56:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:31:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "ray.h"

t_hit_record	hit_circle(t_ray ray, t_shape *shape)
{
	t_hit_record	hr;

	hr = hit_plane(ray, shape);
	if (!hr.is_hit)
		return (hr);
	else if (vec3len(sub_vec3(shape->coord, hr.point)) <= shape->radius)
		return (hr);
	else
	{
		hr.is_hit = FALSE;
		return (hr);
	}
}
