/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:34:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/03 14:38:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft/vec3.h"

t_vec3	multi_vec3(t_vec3 u, t_vec3 v)
{
	return (vec3(u.x * v.x, u.y * v.y, u.z * v.z));
}
