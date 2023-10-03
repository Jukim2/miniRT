/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/04 01:34:23 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

void	parse_camera(t_objects *objects, char *line)
{
	int idx;

	idx = parse_doubles(&objects->camera.coord, line, 1);
	check_misconfiguration(objects, line, idx);
	idx = parse_doubles(&objects->camera.forward_vector, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_double(&objects->camera.fov, line, idx);
	check_endconfiguration(objects, line, idx);
}
