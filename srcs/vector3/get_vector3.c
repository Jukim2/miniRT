/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:22:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 19:23:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	get_vector3(double x, double y, double z)
{
	t_vector3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
