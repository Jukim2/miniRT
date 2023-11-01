/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 14:52:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include <stdio.h>

void	parse_light(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_doubles(&objects->light.coord, line, check_misconfig(objects, line, 1));
	idx = parse_double(&objects->light.brightness, line, check_misconfig(objects, line, idx));
	if (objects->light.brightness < 0 || objects->light.brightness > 1)
	{
		printf("Error\nLight brightness should be between [0.0, 1.0]\n");
		clean_program(objects, line);
	}
	idx = parse_doubles(&objects->light.rgb, line, check_misconfig(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
