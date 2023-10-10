/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:23:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 15:57:32 by gyoon            ###   ########.fr       */
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

t_quat	get_conj_quat(t_quat q);
t_quat	get_rot_quat(t_vec3 u, t_vec3 v);
t_quat	mul_quat(t_quat q1, t_quat q2);
t_quat	norm_quat(t_quat q);
void	print_quat(t_quat q);
double	quatlen(t_quat q);
t_quat	quat(double w, double x, double y, double z);

t_vec3	rot_vec3(t_vec3 v, t_quat rot_quat);
t_quat	vec3_to_quat(t_vec3 v);

#endif
