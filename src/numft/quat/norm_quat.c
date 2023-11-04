/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_quat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:00:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:15:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/quat.h"

t_quat	norm_quat(t_quat q)
{
	double	len;

	len = quatlen(q);
	if (len == 0)
		return (q);
	else
		return (quat(q.w / len, q.v.x / len, q.v.y / len, q.v.z / len));
}
