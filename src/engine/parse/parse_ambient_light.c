/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/03 17:33:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_objects *objs, char *line)
{
	int	idx;

	idx = parse_double(&objs->ambient.ambient, line, \
	check_misconfig(objs, line, 1));
	if (objs->ambient.ambient < 0 || objs->ambient.ambient > 1)
	{
		printf("Error\nAmbient Light should be between [0.0, 1.0]\n");
		clean_program(objs, line);
	}
	idx = parse_doubles(&objs->ambient.rgb, line, \
	check_misconfig(objs, line, idx));
	if (!is_valid_color_hex(objs->ambient.rgb))
	{
		printf("Error\nAmbient Light RGB should be between [0-255]\n");
		clean_program(objs, line);
	}
	objs->ambient.rgb = scale_vec3(1 / 255., objs->ambient.rgb);
	objs->ambient.rgb = scale_vec3(objs->ambient.ambient, objs->ambient.rgb);
	check_endconfig(objs, line, idx);
}
