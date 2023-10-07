/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/07 20:09:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

// normal : n
// center : c (plane point)
// ray origin : o
// ray direction : d
// t = ((N dot C) - (N dot O)) / (N dot D)
double	hit_plane(t_ray ray, t_shape *shape)
{
	double tmp1 = dot_vec3(shape->form_vector, shape->coord);
	double tmp2 = dot_vec3(shape->form_vector, ray.origin);
	double tmp3 = dot_vec3(shape->form_vector, ray.direction);
	
	return ((tmp1 - tmp2) / tmp3);
}
