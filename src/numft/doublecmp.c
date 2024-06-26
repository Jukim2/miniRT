/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublecmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:43:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/01 15:37:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numft.h"

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
