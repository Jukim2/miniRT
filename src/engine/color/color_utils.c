/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:33:12 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/04 17:24:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "numft.h"
#include <math.h>

void	correct_color(t_vec3 *color_vector_sum)
{
	if (color_vector_sum->x > 1)
		color_vector_sum->x = 1;
	if (color_vector_sum->y > 1)
		color_vector_sum->y = 1;
	if (color_vector_sum->z > 1)
		color_vector_sum->z = 1;
}
