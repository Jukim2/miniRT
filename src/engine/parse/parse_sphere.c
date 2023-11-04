/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/04 17:16:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "object.h"
#include "parse.h"
#include "libft.h"
#include <stdio.h>

void	parse_sphere(t_objects *objs, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		term_engine(ERR_MSG_SHAPE_NOT_ALLOC, objs, line);
	tmp->type = SPHERE;
	idx = parse_doubles(&tmp->coord, line, check_misconfig(objs, line, 2));
	idx = parse_double(&tmp->radius, line, check_misconfig(objs, line, idx));
	tmp->radius /= 2;
	if (doublecmp(tmp->radius, 0) <= 0)
		term_engine(ERR_MSG_SPHERE_RADIUS, objs, line);
	idx = parse_doubles(&tmp->rgb, line, check_misconfig(objs, line, idx));
	if (!is_valid_color_hex(tmp->rgb))
		term_engine(ERR_MSG_SHPERE_RGB, objs, line);
	check_endconfig(objs, line, idx);
	tmp->rgb = scale_vec3(1 / 255., tmp->rgb);
	add_shape(&objs->shape, tmp);
}
