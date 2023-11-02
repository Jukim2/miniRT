/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:48 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/02 20:17:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include <stdio.h>

void	parse_light(t_objects *objs, char *line)
{
	int	idx;

	idx = parse_doubles(&objs->light.coord, line, check_misconfig(objs, line, 1));
	idx = parse_double(&objs->light.brightness, line, check_misconfig(objs, line, idx));
	if (objs->light.brightness < 0 || objs->light.brightness > 1)
	{
		printf("Error\nLight brightness should be between [0.0, 1.0]\n");
		clean_program(objs, line);
	}
	idx = parse_doubles(&objs->light.rgb, line, check_misconfig(objs, line, idx));
	check_endconfiguration(objs, line, idx);
}
