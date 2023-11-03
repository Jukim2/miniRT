/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:52:57 by jukim2            #+#    #+#             */
/*   Updated: 2023/11/03 13:55:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	clean_program(t_objects *objs, char *line)
{
	t_shape	*iter;
	t_shape	*tmp;

	iter = objs->shape;
	while (iter)
	{
		tmp = iter;
		iter = iter->next;
		free(tmp);
	}
	free(line);
	exit (0);
}

int	check_misconfig(t_objects *objs, char *line, int idx)
{
	char	ch;

	while (line[idx] == ' ')
		idx++;
	ch = line[idx];
	if (ch != '\n' && ch != '\0' && ch != '+'
		&& ch != '-' && (ch < '0' || ch > '9'))
	{
		printf("Error\nminiRT: file misconfiguration error\n");
		clean_program(objs, line);
	}
	return (idx);
}

void	check_endconfiguration(t_objects *objs, char *line, int idx)
{
	while (line[idx])
	{
		if (line[idx] != ' ' && line[idx] != '\n')
		{
			printf("Error\nminiRT: file misconfiguration error\n");
			clean_program(objs, line);
		}
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
