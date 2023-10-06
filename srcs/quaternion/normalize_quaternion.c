/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_quaternion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:00:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 00:04:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <math.h>

t_quaternion	normalize_quaternion(t_quaternion q)
{
	double	len;

	len = get_quaternion_length(q);
	return (get_quaternion(q.w / len, q.v.x / len, q.v.y / len, q.v.z / len));
}