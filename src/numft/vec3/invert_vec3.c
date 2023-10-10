/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inverse_vec3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:48:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 18:48:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/vec3.h"

t_vec3	invert_vec3(t_vec3 v)
{
	return (vec3(-v.x, -v.y, -v.z));
}