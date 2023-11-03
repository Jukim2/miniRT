/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/03 15:12:02 by gyoon            ###   ########.fr       */
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
	if ((objs->camera.forward.x < -1 || objs->camera.forward.x > 1) || \
		(objs->camera.forward.y < -1 || objs->camera.forward.y > 1) || \
		(objs->camera.forward.z < -1 || objs->camera.forward.z > 1))
	{
		printf("Error\nCamera Orientation Vector must have values in [-1,1]\n");
		clean_program(objs, line);
	}
	else if (doublecmp(vec3len(objs->camera.forward), 0.) <= 0)
	{
		printf("Error\nCamera Orientation Vector should have length\n");
		clean_program(objs, line);
	}
	objs->camera.forward = norm_vec3(objs->camera.forward);
	idx = parse_double(&objs->camera.fov, line, \
	check_misconfig(objs, line, idx));
	if (objs->camera.fov < 0 || objs->camera.fov > 180)
	{
		printf("Error\nCamera field of view should be in [-1,1]\n");
		clean_program(objs, line);
	}
	check_endconfig(objs, line, idx);
}
