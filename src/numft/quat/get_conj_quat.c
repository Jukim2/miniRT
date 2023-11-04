/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conj_quat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:22:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:15:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/quat.h"

t_quat	get_conj_quat(t_quat q)
{
	return (quat(q.w, -q.v.x, -q.v.y, -q.v.z));
}
