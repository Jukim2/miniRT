/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inverse_vector3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:48:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 18:48:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	get_inverse_vector3(t_vector3 i)
{
	t_vector3	result;

	result.x = -i.x;
	result.y = -i.y;
	result.z = -i.z;
	return (result);
}
