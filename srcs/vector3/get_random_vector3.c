/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_vector3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:14:01 by kjs               #+#    #+#             */
/*   Updated: 2023/10/05 11:56:50 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "utils.h"
#include <stdlib.h>
#include <time.h>

t_vector3	get_random_vector3()
{
	// srand(time(NULL));
	// return (get_unit_vector3(get_vector3(random_double(), random_double(), random_double())));
	while (1)
	{
		t_vector3 p = get_vector3(random_double(), random_double(), random_double());
		if (get_vector3_length(p) <= 1)
			return (get_unit_vector3(p));
	}
	// return (get_unit_vector3(get_vector3(rand(), rand(), rand())));
}