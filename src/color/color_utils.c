/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/10 16:46:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "numft.h"
#include <math.h>

void	correct_color(t_vec3 *color_vector_sum, t_shape *hitted_shape)
{
	if (color_vector_sum->x > hitted_shape->rgb.x)
		color_vector_sum->x = hitted_shape->rgb.x;
	if (color_vector_sum->y > hitted_shape->rgb.y)
		color_vector_sum->y = hitted_shape->rgb.y;
	if (color_vector_sum->z > hitted_shape->rgb.z)
		color_vector_sum->z = hitted_shape->rgb.z;
}

t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j)
{
	return (vec3(i.x * j.x, i.y * j.y, i.z * j.z));
}

