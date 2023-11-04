/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_failed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:57:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 01:27:19 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"

void	parse_failed(t_objects *objs, char *line)
{
	term_engine(ERR_MSG_WRONG_SYMBOL, objs, line);
}
