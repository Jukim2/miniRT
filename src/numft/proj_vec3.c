/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:27:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:13:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"

t_vec3	proj_vec3(t_vec3 v, t_vec3 plane_normal)
{
	t_vec3	result;

	result = sub_vec3(v, scale_vec3(dot_vec3(v, plane_normal), plane_normal));
	return (result);
}
