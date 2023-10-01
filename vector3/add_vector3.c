/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_two_vector3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:44:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 18:45:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	add_vector3(t_vector3 i, t_vector3 j)
{
	t_vector3	result;

	result.x = i.x + j.x;
	result.y = i.y + j.y;
	result.z = i.z + j.z;
	return (result);
}
