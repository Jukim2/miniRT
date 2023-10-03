/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 21:25:59 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_double(&objects->ambient_light.light_ratio, line, 1);
	check_misconfiguration(objects, line, idx);
	idx = parse_doubles(&objects->ambient_light.rgb, line, idx);
	check_endconfiguration(objects, line, idx);
}