/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:52:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/31 15:34:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	rand_double(double i, double j)
{
	static unsigned int	seed;
	double				random_value;

	if (seed == 0)
		seed = 12345;
	seed = (unsigned int)(seed * 1664525 + 1013904223);
	random_value = (double)seed / (unsigned int)4294967295;
	return ((j - i) * random_value + i);
}
