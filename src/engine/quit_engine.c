/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:13:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/04 17:24:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

int	quit_engine(void *ptr)
{
	t_engine	*e;

	e = (t_engine *)ptr;
	mlx_clear_window(e->mlx, e->win);
	clean_engine(&e->objs, 0);
	exit(0);
}
