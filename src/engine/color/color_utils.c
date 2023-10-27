/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/27 12:45:58 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "numft.h"
#include <math.h>

void	correct_color(t_vec3 *color_vector_sum, t_shape *hitted_shape)
{
	if (color_vector_sum->x > 1)
		color_vector_sum->x = 1;
	if (color_vector_sum->y > 1)
		color_vector_sum->y = 1;
	if (color_vector_sum->z > 1)
		color_vector_sum->z = 1;
}

t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j)
{
	return (vec3(i.x * j.x, i.y * j.y, i.z * j.z));
}

