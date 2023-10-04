/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_vector3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:01 by kjs               #+#    #+#             */
/*   Updated: 2023/10/04 17:39:24 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "utils.h"
#include <stdlib.h>

t_vector3	get_random_vector3()
{
	// return (get_unit_vector3(get_vector3(random_double(), random_double(), random_double())));
	return (get_unit_vector3(get_vector3(rand(), rand(), rand())));
}