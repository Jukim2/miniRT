/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:13:42 by kjs               #+#    #+#             */
/*   Updated: 2023/10/05 12:10:33 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Custom pseudo-random number generator in the range [-1.0, 1.0]
#include <stdio.h>

double	random_double() 
{    
	static unsigned int seed;

	if (seed == 0)
		seed = 12345;
	seed = (unsigned int)(seed * 1664525 + 1013904223);
    double random_value = (double)seed / (unsigned int)4294967295;
	
    return 2.0 * random_value - 1.0;
}