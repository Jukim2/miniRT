/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quaternion_length.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:01:48 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 00:03:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"
#include <math.h>

double	get_quaternion_length(t_quaternion q)
{
	return (sqrt(q.w * q.w + q.v.x * q.v.x + q.v.y * q.v.y + q.v.z * q.v.z));
}
