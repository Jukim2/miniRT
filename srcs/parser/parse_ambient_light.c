/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:51:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 12:53:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"

#include <stdio.h>

void	parse_ambient_light(t_object *objects, char *line)
{
	int	idx;

	idx = parse_float(&objects->ambient_light.light_ratio, line, 1);
	check_misconfiguration(objects, line, idx);
	idx = parse_rgb(objects->ambient_light.rgb, line, idx);
	check_endconfiguration(objects, line, idx);
}