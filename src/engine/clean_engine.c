/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:16:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/04 16:23:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

void	clean_engine(t_objects *objs, char *line)
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
}
