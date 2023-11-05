/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:46 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/05 10:38:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "parse.h"
#include "libft.h"

void	parse_cylinder(t_objects *objs, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		term_engine(ERR_MSG_SHAPE_NOT_ALLOC, objs, line);
	tmp->type = CYLINDER;
	idx = parse_doubles(&tmp->coord, line, check_misconfig(objs, line, 2));
	idx = parse_doubles(&tmp->orient, line, check_misconfig(objs, line, idx));
	if (!is_valid_norm_vector(tmp->orient))
		term_engine(ERR_MSG_CY, objs, line);
	else if (doublecmp(vec3len(tmp->orient), 0.) <= 0)
		term_engine(ERR_MSG_CY_ORIENT_LEN, objs, line);
	tmp->orient = norm_vec3(tmp->orient);
	idx = parse_double(&tmp->radius, line, check_misconfig(objs, line, idx));
	tmp->radius /= 2;
	idx = parse_double(&tmp->height, line, check_misconfig(objs, line, idx));
	idx = parse_doubles(&tmp->rgb, line, check_misconfig(objs, line, idx));
	if (!is_valid_color_hex(tmp->rgb))
		term_engine(ERR_MSG_CY_RGB, objs, line);
	tmp->rgb = scale_vec3(1 / 255., tmp->rgb);
	check_endconfig(objs, line, idx);
	add_shape(&objs->shape, tmp);
}
