/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/06 15:48:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

int	convert_color_vec3(t_vec3 color_vec3)
{
	// return (((int)((color_vec3.x) * 255)) << 16 | \
	// 		((int)((color_vec3.y) * 255)) << 8 | \
	// 		((int)((color_vec3.z) * 255)));
	return (((int)(sqrt(color_vec3.x) * 255)) << 16 | \
			((int)(sqrt(color_vec3.y) * 255)) << 8 | \
			((int)(sqrt(color_vec3.z) * 255)));
}

t_vec3	multiply_color_vec3(t_vec3 i, t_vec3 j)
{
	return (vec3(i.x * j.x, i.y * j.y, i.z * j.z));
}
