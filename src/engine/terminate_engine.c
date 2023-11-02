/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:13:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/02 21:30:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "parse.h"
#include <stdlib.h>

int	terminate_engine(t_engine *e)
{
	mlx_clear_window(e->mlx, e->win);
	clean_program(&e->objs, 0);
	exit(0);
	return (0);
}
