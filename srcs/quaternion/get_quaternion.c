/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quaternion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:48:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 23:50:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	get_quaternion(double w, double x, double y, double z)
{
	t_quaternion	q;

	q.w = w;
	q.v = get_vector3(x, y, z);
	return (q);
}
