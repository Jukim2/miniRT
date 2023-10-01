/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtract_vector3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:44:50 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 19:00:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	subtract_vector3(t_vector3 i, t_vector3 j)
{
	return (add_vector3(i, get_inverse_vector3(j)));
}
