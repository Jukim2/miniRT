/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:08:35 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/10 16:44:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/vec3.h"

t_vec3	cross_vec3(t_vec3 u, t_vec3 v)
{
	return (vec3(u.y * v.z - u.z * v.y, \
				u.z * v.x - u.x * v.z, \
				u.x * v.y - u.y * v.x));
}