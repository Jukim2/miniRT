/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:46 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/03 12:54:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"
#include <stdlib.h>

void	parse_cylinder(t_object *objects, char *line)
{
	t_cylinder	*tmp;
	int			idx;

	tmp = ft_calloc(1, sizeof(t_cylinder));
	if (!tmp)
		clean_program(objects, line);
	idx = parse_floats(tmp->coord, line, 2);
	check_misconfiguration(objects, line, idx);
	idx = parse_floats(tmp->normal_vector, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_float(&tmp->diameter, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_float(&tmp->height, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_rgb(tmp->rgb, line, idx);
	check_endconfiguration(objects, line, idx);
	add_cylinder(objects->cylinder, tmp);
}

void	add_cylinder(t_cylinder *cylinder, t_cylinder *new)
{
	if (!cylinder)
		cylinder = new;
	else
	{
		while (cylinder->next)
			cylinder = cylinder->next;
		cylinder->next = new;
	}
}
