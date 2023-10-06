/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_quat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:00:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 00:04:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quat.h"
#include <math.h>

t_quat	norm_quat(t_quat q)
{
	double	len;

	len = quatlen(q);
	return (quat(q.w / len, q.v.x / len, q.v.y / len, q.v.z / len));
}
