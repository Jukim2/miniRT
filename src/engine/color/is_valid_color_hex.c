/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_color_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:30:09 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/03 17:31:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"

t_bool	is_valid_color_hex(t_vec3 color)
{
	if ((color.x < 0 || color.x > 255) || (color.y < 0 || color.y > 255) || \
		(color.z < 0 || color.z > 255))
		return (FALSE);
	else
		return (TRUE);
}
