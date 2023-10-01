/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector3_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:50:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 18:52:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <math.h>

double	get_vector3_length(t_vector3 i)
{
	return (sqrt(i.x * i.x + i.y * i.y + i.z * i.z));
}
