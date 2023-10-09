/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:02:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/09 15:55:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

// normal : n
// center : c (plane point)
// ray origin : o
// ray direction : d
// t = ((N dot C) - (N dot O)) / (N dot D)
double	hit_plane(t_ray ray, t_shape *shape)
{
	t_vec3	o_c;
	double	n_dot_c;
	double	n_dot_d;

	o_c = sub_vec3(ray.origin, shape->coord);

	n_dot_c = dot_vec3(shape->form_vector, sub_vec3(shape->coord, ray.origin));
	n_dot_d = dot_vec3(shape->form_vector, ray.direction);
	return (n_dot_c / n_dot_d);
}
