/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:52:57 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/04 16:55:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	check_misconfig(t_objects *objs, char *line, int idx)
{
	char	ch;

	while (line[idx] == ' ')
		idx++;
	ch = line[idx];
	if (ch != '\n' && ch != '\0' && ch != '+'
		&& ch != '-' && (ch < '0' || ch > '9'))
		term_engine("miniRT: file misconfiguration error", objs, line);
	return (idx);
}

void	check_endconfig(t_objects *objs, char *line, int idx)
{
	while (line[idx])
	{
		if (line[idx] != ' ' && line[idx] != '\n')
			term_engine("miniRT: file misconfiguration error", objs, line);
		idx++;
	}
}

void	add_shape(t_shape **shape, t_shape *new)
{
	t_shape	*tmp;

	tmp = *shape;
	if (!*shape)
		*shape = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_bool	is_valid_norm_vector(t_vec3	n)
{
	if ((n.x < -1 || n.x > 1) || (n.y < -1 || n.y > 1) || (n.z < -1 || n.z > 1))
		return (FALSE);
	else
		return (TRUE);
}
