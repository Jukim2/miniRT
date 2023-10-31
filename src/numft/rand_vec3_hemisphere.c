/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_vec3_hemisphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:52:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/31 15:34:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"
#include "object.h"

t_vec3	rand_vec3_hemisphere(t_vec3 v)
{
	const t_vec3	rand_vector = rand_vec3();

	if (dot_vec3(v, rand_vector) > 0.)
		return (rand_vector);
	else
		return (invert_vec3(rand_vector));
}
