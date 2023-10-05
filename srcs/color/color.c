/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/05 23:28:56 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <math.h>

int	convert_color_vector3(t_vector3 color_vec3)
{
	// return (((int)((color_vec3.x) * 255)) << 16 | \
	// 		((int)((color_vec3.y) * 255)) << 8 | \
	// 		((int)((color_vec3.z) * 255)));
	return (((int)(sqrt(color_vec3.x) * 255)) << 16 | \
			((int)(sqrt(color_vec3.y) * 255)) << 8 | \
			((int)(sqrt(color_vec3.z) * 255)));
}

t_vector3	multiply_color_vector3(t_vector3 i, t_vector3 j)
{
	return (get_vector3(i.x * j.x, i.y * j.y, i.z * j.z));
}
