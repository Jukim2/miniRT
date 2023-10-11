/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 21:56:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMFT_H
# define NUMFT_H

# include "numft/vec3.h"
# include "numft/quat.h"

# define PI 3.141592

enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

/* ===============./numft================ */

t_vec3	rot_vec3(t_vec3 v, t_quat rot_quat);
double	rand_double(double i, double j);
t_vec3	rand_vec3_hemisphere(t_vec3 v);
t_quat	vec3_to_quat(t_vec3 v);
double	get_radian(double degrees);

#endif
