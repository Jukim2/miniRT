/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:35:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:26:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include <math.h>

int	convert_color_vec3(t_vec3 color)
{
	if (color.x <= 0)
		color.x = 0;
	if (color.y <= 0)
		color.y = 0;
	if (color.z <= 0)
		color.z = 0;
	return (((int)(sqrt(color.x) * 255)) << 16 | \
			((int)(sqrt(color.y) * 255)) << 8 | \
			((int)(sqrt(color.z) * 255)));
}
