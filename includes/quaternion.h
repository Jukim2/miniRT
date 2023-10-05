/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:23:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/05 00:27:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

#include "vector3.h"

typedef struct s_quaternion
{
	double		w;
	t_vector3	v;
}	t_quaternion;

t_quaternion	get_conjugate_quaternion(t_quaternion q);
t_quaternion	get_quaternion(double w, double x, double y, double z);
double			get_quaternion_length(t_quaternion q);
t_quaternion	normalize_quaternion(t_quaternion q);
t_quaternion	product_quaternion(t_quaternion q1, t_quaternion q2);

#endif
