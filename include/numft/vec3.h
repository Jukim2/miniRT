/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:41:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/06 15:06:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/* ===============./math3d/vec3=============== */

t_vec3	scale_vec3(double c, t_vec3 v);
t_vec3	add_vec3(t_vec3 u, t_vec3 v);
t_vec3	norm_vec3(t_vec3 v);
t_vec3	vec3(double x, double y, double z);
void	print_vec3(t_vec3 v);
t_vec3	invert_vec3(t_vec3 v);
t_vec3	rand_vec3(void);
double	vec3len(t_vec3 v);
t_vec3	cross_vec3(t_vec3 u, t_vec3 v);
t_vec3	sub_vec3(t_vec3 u, t_vec3 v);
double	dot_vec3(t_vec3 u, t_vec3 v);

#endif
