/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/26 14:33:04 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_double(&objects->ambient_light.light_ratio, line, \
	check_misconfiguration(objects, line, 1));
	idx = parse_doubles(&objects->ambient_light.rgb, line, \
	check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}