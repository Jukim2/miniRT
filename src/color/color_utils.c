/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/07 11:21:53 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "object.h"
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

int	convert_color_vec3(t_vec3 color_vec3)
{
	return (((int)(sqrt(color_vec3.x) * 255)) << 16 | \
			((int)(sqrt(color_vec3.y) * 255)) << 8 | \
			((int)(sqrt(color_vec3.z) * 255)));
}

t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j)
{
	return (vec3(i.x * j.x, i.y * j.y, i.z * j.z));
}

