/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublecmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:43:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/30 14:59:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"

static double	abs_double(double d)
{
	if (d >= 0.)
		return (d);
	else
		return (-d);
}

int	doublecmp(double d1, double d2)
{
	double	diff;

	diff = abs_double(d1 - d2);
	if (diff < 0.000001)
		return (0);
	else if (d1 > d2)
		return (1);
	else
		return (-1);
}
