/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:13:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/04 16:52:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

void	quit_engine(t_engine *e)
{
	mlx_clear_window(e->mlx, e->win);
	clean_engine(&e->objs, 0);
	exit(0);
}
