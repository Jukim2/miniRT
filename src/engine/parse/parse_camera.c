/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 14:52:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include <stdio.h>

void	parse_camera(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_doubles(&objects->camera.coord, line, \
	check_misconfig(objects, line, 1));
	idx = parse_doubles(&objects->camera.forward, line, \
	check_misconfig(objects, line, idx));
	if (doublecmp(vec3len(objects->camera.forward), 0.) <= 0)
	{
		printf("Error\ncamera orientation vector should have length\n");
		clean_program(objects, line);
	}
	else
		objects->camera.forward = norm_vec3(objects->camera.forward);
	idx = parse_double(&objects->camera.fov, line, \
	check_misconfig(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
