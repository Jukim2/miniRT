/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_quat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/31 17:05:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include <math.h>
#include <stdio.h>

// q = cos(θ/2) + (x * sin(θ/2), y * sin(θ/2), z * sin(θ/2))
t_quat	get_rot_quat(t_vec3 u, t_vec3 v)
{
	t_quat	q;
	t_vec3	c;
	double	cos;
	double	sin_half;
	double	cos_half;

	c = cross_vec3(u, v);
	if (doublecmp(vec3len(c), 0) != 0)
		c = norm_vec3(c);
	printf("cross: ");
	print_vec3(c);
	cos = dot_vec3(u, v);
	if (doublecmp(cos, 1.) == 0)
		return (quat(1, 0, 0, 0));
	else if (doublecmp(cos, -1.) == 0)
		return (quat(0, 1, 0, 0));
	sin_half = sqrt((1.0 - cos) / 2.0);
	cos_half = sqrt((1.0 + cos) / 2.0);
	// printf("cos half: %.40f\n", cos);
	q = quat(cos_half, c.x * sin_half, c.y * sin_half, c.z * sin_half);
	q = norm_quat(q);
	return (q);
}
