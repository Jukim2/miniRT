/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:23:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 16:43:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUAT_H
# define QUAT_H

# include "vec3.h"

typedef struct s_quat
{
	double	w;
	t_vec3	v;
}	t_quat;

/* ===============./math3d/quat=============== */

t_quat	quat(double w, double x, double y, double z);
void	print_quat(t_quat q);
t_quat	get_conj_quat(t_quat q);
t_quat	norm_quat(t_quat q);
t_quat	get_rot_quat(t_vec3 u, t_vec3 v);
double	quatlen(t_quat q);
t_quat	mul_quat(t_quat q1, t_quat q2);t_quat	mul_quat(t_quat q1, t_quat q2);
t_quat	norm_quat(t_quat q);
void	print_quat(t_quat q);
double	quatlen(t_quat q);
t_quat	quat(double w, double x, double y, double z);

#endif
