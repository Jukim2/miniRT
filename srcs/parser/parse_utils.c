/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:52:57 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 20:21:18 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stdio.h>
#include <stdlib.h>

void	clean_program(t_object *objects, char *line)
{
    // ~
	exit (0);
}

void	check_misconfiguration(t_object *objects, char *line, int idx)
{
	if (line[idx] != ' ' && line[idx] != '\n' && line[idx] != '\0')
	{
        perror("Error: Argument Error");
		clean_program(objects, line);
	}
}

void	check_endconfiguration(t_object *objects, char *line, int idx)
{
	while (line[idx])
	{
		if (line[idx] != ' ' && line[idx] != '\n')
		{
			perror("Error: line end error");
			clean_program(objects, line);
		}
		idx++;
	}
}