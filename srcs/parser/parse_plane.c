/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 20:10:36 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"

void	parse_plane(t_object *objects, char *line)
{
	t_plane		*tmp;
	int			idx;
	
	tmp= ft_calloc(1, sizeof(t_plane));
	if (!tmp)
		clean_program(objects, line);
	idx = parse_floats(tmp->coord, line, 2);
	check_misconfiguration(objects, line, idx);
	idx = parse_floats(tmp->normal_vector, line , idx);
	check_misconfiguration(objects, line, idx);
	idx = parse_rgb(tmp->rgb, line, idx);
	check_endconfiguration(objects, line, idx);
	add_plane(objects->plane, tmp);
}

void	add_plane(t_plane *plane, t_plane *new)
{
	if (!plane)
		plane = new;
	else
	{
		while (plane->next)
			plane = plane->next;
		plane->next = new;
	}
}