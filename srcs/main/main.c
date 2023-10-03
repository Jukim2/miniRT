/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:00 by kjs               #+#    #+#             */
/*   Updated: 2023/10/03 21:31:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "parse.h"
#include "libft.h"
#include "ray.h"
#include "mlx.h"
#include "vector3.h"
#include "image.h"
#include <math.h>
#include <stdio.h>

void	initialize_objects(t_objects *objects)
{
	ft_bzero(objects, sizeof(t_objects));
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_objects	objects;


	initialize_objects(&objects);
	parse(&objects, argv[1]);

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	img.img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = (unsigned int*)mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);

	float	focal_length = 1.f; // 카메라의 초점거리
	float	viewport_height = 5.f;
	float	viewport_width = 10.f;
	float	pixel_delta_x = viewport_width / 1024;
	float	pixel_delta_y = viewport_height / 512;

	t_vector3	top_left_pixel;
	top_left_pixel.x = -viewport_width / 2. + pixel_delta_x * 0.5;
	top_left_pixel.y = -viewport_height / 2. + pixel_delta_y * 0.5;
	top_left_pixel.z = -focal_length;

	t_vector3	pixel_center;
	t_ray		ray;

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 512; j++)
		{

			pixel_center = add_vector3(top_left_pixel, get_vector3(i * pixel_delta_x, j * pixel_delta_y, 0));
			ray.origin = ob; // camera center;
			ray.direction = subtract_vector3(pixel_center, get_vector3(0, 0, 0));
			ray.direction = get_unit_vector3(ray.direction); // get unit_vector

			t_vector3 color_vector = get_color_vector3(ray);
			img.addr[j * img.line_length / 4 + i] = convert_color_vector3(color_vector); 
		} 
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
	return (0);
}
