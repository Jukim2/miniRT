/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/01 14:53:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"
#include <stdio.h>

void	parse_plane(t_objects *objects, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		clean_program(objects, line);
	tmp->type = PLANE;
	idx = parse_doubles(&tmp->coord, line, check_misconfig(objects, line, 2));
	idx = parse_doubles(&tmp->orient, line, check_misconfig(objects, line, idx));
	if (doublecmp(vec3len(tmp->orient), 0.) <= 0)
	{
		printf("Error\nplane orientation vector should have length\n");
		clean_program(objects, line);
	}
	else
		tmp->orient = norm_vec3(tmp->orient);
	idx = parse_doubles(&tmp->rgb, line, check_misconfig(objects, line, idx));
	tmp->rgb = scale_vec3(1 / 255., tmp->rgb);
	check_endconfiguration(objects, line, idx);
	add_shape(&objects->shape, tmp);
}
