/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/30 13:51:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "numft.h"
#include <math.h>

void	correct_color(t_vec3 *color_vector_sum, t_vec3 rgb)
{
	if (color_vector_sum->x > rgb.x)
		color_vector_sum->x = rgb.x;
	if (color_vector_sum->y > rgb.y)
		color_vector_sum->y = rgb.y;
	if (color_vector_sum->z > rgb.z)
		color_vector_sum->z = rgb.z;
}

t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j)
{
	return (vec3(i.x * j.x, i.y * j.y, i.z * j.z));
}

