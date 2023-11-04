/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:27:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/04 16:35:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <stdlib.h>

void	term_engine(char *errmsg, t_objects *objs, char *line)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(errmsg, 2);
	clean_engine(objs, line);
	exit(1);
}
