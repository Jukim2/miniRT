/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 10:37:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"

void	parse_camera(t_objects *objs, char *line)
{
	int	idx;

	idx = parse_doubles(&objs->camera.coord, line, \
	check_misconfig(objs, line, 1));
	idx = parse_doubles(&objs->camera.forward, line, \
	check_misconfig(objs, line, idx));
	if (!is_valid_norm_vector(objs->camera.forward))
		term_engine(ERR_MSG_CAM, objs, line);
	else if (doublecmp(vec3len(objs->camera.forward), 0.) <= 0)
		term_engine(ERR_MSG_CAM_ORIENT_LEN, objs, line);
	objs->camera.forward = norm_vec3(objs->camera.forward);
	idx = parse_double(&objs->camera.fov, line, \
	check_misconfig(objs, line, idx));
	if (objs->camera.fov < 0 || objs->camera.fov > 180)
		term_engine(ERR_MSG_CAM_FOV, objs, line);
	check_endconfig(objs, line, idx);
}
