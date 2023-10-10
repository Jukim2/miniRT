/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_quat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:08:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 14:50:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/quat.h"

t_quat	mul_quat(t_quat q1, t_quat q2)
{
	t_quat	q;

	q.w = q1.w * q2.w - (q1.v.x * q2.v.x + q1.v.y * q2.v.y + q1.v.z * q2.v.z);
	q.v.x = q1.w * q2.v.x + q1.v.x * q2.w + q1.v.y * q2.v.z - q1.v.z * q2.v.y;
	q.v.y = q1.w * q2.v.y + q1.v.y * q2.w + q1.v.z * q2.v.x - q1.v.x * q2.v.z;
	q.v.z = q1.w * q2.v.z + q1.v.z * q2.w + q1.v.x * q2.v.y - q1.v.y * q2.v.x;
	return (q);
}
