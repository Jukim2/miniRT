/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:46 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/31 14:57:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

void	parse_cylinder(t_objects *objects, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		clean_program(objects, line);
	tmp->type = CYLINDER;
	idx = parse_doubles(&tmp->coord, line, check_misconfiguration(objects, line, 2));
	idx = parse_doubles(&tmp->orient, line, check_misconfiguration(objects, line, idx));
	idx = parse_double(&tmp->radius, line, check_misconfiguration(objects, line, idx));
	tmp->radius /= 2;
	idx = parse_double(&tmp->height, line, check_misconfiguration(objects, line, idx));
	idx = parse_doubles(&tmp->rgb, line, check_misconfiguration(objects, line, idx));
	tmp->rgb = scale_vec3(1 / 255., tmp->rgb);
	check_endconfiguration(objects, line, idx);
	add_shape(&objects->shape, tmp);
}
