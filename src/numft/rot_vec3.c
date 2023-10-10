/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:14:50 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 16:45:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"

t_vec3	rot_vec3(t_vec3 v, t_quat rot_quat)
{
	t_quat	a;
	t_quat	result;

	a = vec3_to_quat(v);
	result = mul_quat(mul_quat(rot_quat, a), get_conj_quat(rot_quat));
	return (result.v);
}
