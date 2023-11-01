/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:37:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/01 15:38:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	abs_double(double d)
{
	if (d >= 0.)
		return (d);
	else
		return (-d);
}
