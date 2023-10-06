/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_vector3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:42:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/06 14:42:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	cross_product_vector3(t_vector3 i, t_vector3 j)
{
	return (get_vector3(i.y * j.z - i.z * j.y, i.z * j.x - i.x * j.z, i.x * j.y - i.y * j.x));
}