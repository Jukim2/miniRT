/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_quat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:05:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 16:06:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quat.h"
#include "vec3.h"
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
	if (vec3len(c) > 0.001 || vec3len(c) < -0.001) // (0, 0, 1) 일때도 문제
		c = norm_vec3(c);
	cos = dot_vec3(u, v);
	if (cos < 1)
		printf("cos : %f\n", cos);
	sin_half = sqrt((1.0 - cos) / 2.0);
	cos_half = sqrt((1.0 + cos) / 2.0);	
	q = quat(cos_half, c.x * sin_half, c.y * sin_half, c.z * sin_half);
	q = norm_quat(q);
	return (q);
}
