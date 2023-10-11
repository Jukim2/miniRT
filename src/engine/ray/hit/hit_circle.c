/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:56:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/11 16:45:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "numft.h"

// t_hit_record	hit_circle(t_ray ray, t_vec3 c, t_vec3 n, double r)
// {
// 	t_shape			circle;
// 	t_hit_record	record;


// 	circle.next = 0;
// 	circle.type = PLANE;
// 	circle.face = 0;
// 	circle.material = 0;
// 	circle.diameter = 2 * r;
// 	circle.height = 0;
// 	circle.coord = c;
// 	record = hit_plane(ray, &circle);

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
