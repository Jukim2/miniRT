/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 14:51:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_double(&objects->ambient_light.ambient, line, \
	check_misconfig(objects, line, 1));
	if (objects->ambient_light.ambient < 0 || objects->ambient_light.ambient > 1)
	{
		printf("Error\nAmbient Light should be between [0.0, 1.0]\n");
		clean_program(objects, line);
	}
	idx = parse_doubles(&objects->ambient_light.rgb, line, \
	check_misconfig(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
