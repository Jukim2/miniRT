/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/26 16:40:37 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"


#include <stdio.h>
void	parse_camera(t_objects *objects, char *line)
{
	int idx;

	idx = parse_doubles(&objects->camera.coord, line, \
	check_misconfiguration(objects, line, 1));
	idx = parse_doubles(&objects->camera.forward_vector, line, \
	check_misconfiguration(objects, line, idx));
	idx = parse_double(&objects->camera.fov, line, \
	check_misconfiguration(objects, line, idx));
	check_endconfiguration(objects, line, idx);
}
