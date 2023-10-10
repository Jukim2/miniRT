/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_vec3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:35:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 16:45:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include <math.h>

int	convert_color_vec3(t_vec3 color_vec3)
{
	return (((int)(sqrt(color_vec3.x) * 255)) << 16 | \
			((int)(sqrt(color_vec3.y) * 255)) << 8 | \
			((int)(sqrt(color_vec3.z) * 255)));
}
