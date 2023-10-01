/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unit_vector3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:49:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 18:57:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	get_unit_vector3(t_vector3 i)
{
	t_vector3	result;
	double		length;

	length = get_vector3_length(i);
	result.x = i.x / length;
	result.y = i.y / length;
	result.z = i.z / length;
	return (result);
}
