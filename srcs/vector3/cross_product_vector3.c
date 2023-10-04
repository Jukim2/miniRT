/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_vector3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:17:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 23:22:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	cross_product_vector3(t_vector3 u, t_vector3 v)
{
	double	x;
	double	y;
	double	z;

	x = u.y * v.z - u.z * v.y;
	y = -(u.x * v.z) + u.z * v.x;
	z = u.x * v.y - u.y * v.x;
	return (get_vector3(x, y, z));
}
