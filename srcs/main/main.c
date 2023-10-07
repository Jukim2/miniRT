/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/10/07 20:40:25 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#include "mlx.h"
#include <stdio.h>
// unsigned int	*earth;

int	main(int argc, char **argv)
{
	t_engine	e;

	init_engine(&e, argv[1]);
	int		w, h;
	earth.ptr = mlx_xpm_file_to_image(e.mlx, "earth.xpm", &w, &h);
	earth.addr = (unsigned int *)mlx_get_data_addr(earth.ptr, \
													&earth.bpp, \
													&earth.line_len, \
													&earth.endian);
	// execute_engine(&e);
	printf("w : %d h : %d\n", w, h);
	for (int i = 0; i < 100; i++)
		printf("%d\n", earth.addr[i]);
		// earth.addr[i] = 0;
	mlx_put_image_to_window(e.mlx, e.win, earth.ptr, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
