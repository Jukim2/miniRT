/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/10/28 01:22:18 by kjs              ###   ########.fr       */
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
	earth.ptr = mlx_xpm_file_to_image(e.mlx, "earthmap.xpm", &w, &h);
	earth.addr = (unsigned int *)mlx_get_data_addr(earth.ptr, \
													&earth.bpp, \
													&earth.line_len, \
													&earth.endian);
	int		w2, h2;												
	earth_bump.ptr = mlx_xpm_file_to_image(e.mlx, "bump.xpm", &w2, &h2);
	earth_bump.addr = (unsigned int *)mlx_get_data_addr(earth_bump.ptr, \
													&earth_bump.bpp, \
													&earth_bump.line_len, \
													&earth_bump.endian);
											
	printf("w : %d h : %d\n", w, h);
	execute_engine(&e);
	// t_image new_img;
	// new_img.ptr = mlx_new_image(e.mlx, w, h);
	// new_img.addr = (unsigned int*)mlx_get_data_addr(new_img.ptr, \
	// 									&new_img.bpp, \
	// 									&new_img.line_len, \
	// 									&new_img.endian);
	// for (int i = 0; i < w; i++)
	// {
	// 	for (int j = 0; j < h; j++)
	// 	{
	// 		new_img.addr[j * new_img.line_len /4  + i] = earth.addr[j * earth.line_len/4 + i];
	// 		unsigned int color = new_img.addr[j * new_img.line_len /4  + i];
	// 		int r = (color >> 16) & 0xff;
	// 		int g = (color >> 8) & 0xff;
	// 		int b = color & 0xff;
	// 	}
	// }
	// mlx_put_image_to_window(e.mlx, e.win, new_img.ptr, 0, 0);
	// mlx_loop(e.mlx);
	return (0);
}
