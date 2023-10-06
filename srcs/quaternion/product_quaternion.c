/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_quaternion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:08:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 14:50:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	product_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	result;

	result.w = q1.w * q2.w - (q1.v.x * q2.v.x + q1.v.y * q2.v.y + q1.v.z * q2.v.z);
	result.v.x = q1.w * q2.v.x + q1.v.x * q2.w + q1.v.y * q2.v.z - q1.v.z * q2.v.y;
	result.v.y = q1.w * q2.v.y + q1.v.y * q2.w + q1.v.z * q2.v.x - q1.v.x * q2.v.z;
	result.v.z = q1.w * q2.v.z + q1.v.z * q2.w + q1.v.x * q2.v.y - q1.v.y * q2.v.x;
	return (result);
}
