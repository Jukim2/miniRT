/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conjugate_quaternion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:22:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 00:27:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	get_conjugate_quaternion(t_quaternion q)
{
	return (get_quaternion(q.w, -q.v.x, -q.v.y, -q.v.z));
}
