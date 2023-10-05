/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/05 20:01:51 by jukim2           ###   ########.fr       */
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
