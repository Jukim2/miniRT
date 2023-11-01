/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 13:25:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_camera(t_objects *objects, char *line)
{
	int	idx;

	idx = parse_doubles(&objects->camera.coord, line, \
	check_misconfiguration(objects, line, 1));
	idx = parse_doubles(&objects->camera.forward, line, \
	check_misconfiguration(objects, line, idx));
	idx = parse_double(&objects->camera.fov, line, \
	check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
