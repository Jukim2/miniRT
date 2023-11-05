/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:13:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 11:07:18 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdlib.h>

int	quit_engine(void *ptr)
{
	t_engine	*e;

	e = (t_engine *)ptr;
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.ptr);
	clean_engine(&e->objs, 0);
	exit(0);
}
