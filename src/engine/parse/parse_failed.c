/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_failed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:57:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/04 17:05:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

void	parse_failed(t_objects *objs, char *line)
{
	term_engine(ERR_MSG_WRONG_SYMBOL, objs, line);
}
