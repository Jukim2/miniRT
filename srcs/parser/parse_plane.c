/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/04 01:41:37 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

void	parse_plane(t_objects *objects, char *line)
{
	t_shape	*tmp;
	int		idx;

	tmp = ft_calloc(1, sizeof(t_shape));
	if (!tmp)
		clean_program(objects, line);
	tmp->type = PLANE;
	idx = parse_doubles(&tmp->coord, line, 2);
	check_misconfiguration(objects, line, idx);
	idx = parse_doubles(&tmp->normal_vector, line, idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_doubles(&tmp->rgb, line, idx);
	check_endconfiguration(objects, line, idx);
	add_shape(&objects->shape, tmp);
}
