/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_vector3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:12:24 by kjs               #+#    #+#             */
/*   Updated: 2023/10/05 23:13:56 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	cross_product_vector3(t_vector3 i, t_vector3 j)
{
	return (get_vector3(i.y * j.z - i.z * j.y, i.z * j.x - i.x * j.z, i.x * j.y - i.y * j.x));
}