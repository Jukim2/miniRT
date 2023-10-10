/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:56:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 16:49:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "numft.h"


// double	hit_circle(t_ray ray, t_shape *shape)
// {
// 	double	t;
// 	t_vec3	inter_point;

// 	t = hit_plane(ray, shape);
// 	if (t == -1)
// 		return (t);
// 	else
// 	{
// 		inter_point = add_vec3(shape.coord, scale_vec3(t, shape.form_vector));
// 		if (vec3len(sub_vec3(shape.origin, inter_point) < shape.diameter / 2.);
// 			return (t);
// 		else
// 			return (-1);
// 	}
// }
