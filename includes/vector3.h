/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:41:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/06 14:41:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

/* ===============srcs/vector3=============== */

double		dot_product_vector3(t_vector3 i, t_vector3 j);
t_vector3	multiple_vector3(double t, t_vector3 i);
void		print_vector3(t_vector3 vec);
double		get_vector3_length(t_vector3 i);
t_vector3	cross_product_vector3(t_vector3 u, t_vector3 v);
t_vector3	subtract_vector3(t_vector3 i, t_vector3 j);
t_vector3	add_vector3(t_vector3 i, t_vector3 j);
t_vector3	get_vector3(double x, double y, double z);
t_vector3	get_unit_vector3(t_vector3 i);
t_vector3	get_random_vector3();
t_vector3	get_inverse_vector3(t_vector3 i);
t_vector3	cross_product_vector3(t_vector3 i, t_vector3 j);

#endif
