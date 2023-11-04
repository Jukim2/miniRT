/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:21:48 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:25:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"

void	correct_color(t_vec3 *color_sum)
{
	if (color_sum->x > 1)
		color_sum->x = 1;
	if (color_sum->y > 1)
		color_sum->y = 1;
	if (color_sum->z > 1)
		color_sum->z = 1;
}
