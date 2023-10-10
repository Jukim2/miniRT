/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:13:42 by kjs               #+#    #+#             */
/*   Updated: 2023/10/07 16:27:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	random_double()
{
	// return ((double)rand() * 2 / (double)RAND_MAX - 1);
	static unsigned int seed;

	if (seed == 0)
		seed = 12345;
	seed = (unsigned int)(seed * 1664525 + 1013904223);
    double random_value = (double)seed / (unsigned int)4294967295;

	return (2.0 * random_value - 1.0);
}

double	random_double_zerone()
{
	static unsigned int	seed;

	if (seed == 0)
		seed = 12345;
	seed = (unsigned int)(seed * 1664525 + 1013904223);
	double random_value = (double)seed / (unsigned int)4294967295;

	return random_value;
}
