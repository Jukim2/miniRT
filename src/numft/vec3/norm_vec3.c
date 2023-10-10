/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:49:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 18:57:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/vec3.h"

t_vec3	norm_vec3(t_vec3 v)
{
	double	len;

	len = vec3len(v);
	return (vec3(v.x / len, v.y / len, v.z / len));
}