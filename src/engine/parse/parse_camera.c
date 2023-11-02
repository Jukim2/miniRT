/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/02 20:07:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include <stdio.h>

void	parse_camera(t_objects *objs, char *line)
{
	int	idx;

	idx = parse_doubles(&objs->camera.coord, line, \
	check_misconfig(objs, line, 1));
	idx = parse_doubles(&objs->camera.forward, line, \
	check_misconfig(objs, line, idx));
	if (doublecmp(vec3len(objs->camera.forward), 0.) <= 0)
	{
		printf("Error\ncamera orientation vector should have length\n");
		clean_program(objs, line);
	}
	else
		objs->camera.forward = norm_vec3(objs->camera.forward);
	idx = parse_double(&objs->camera.fov, line, \
	check_misconfig(objs, line, idx));
	check_endconfiguration(objs, line, idx);
}
