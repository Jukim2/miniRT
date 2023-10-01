/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 20:20:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector3.h"
#include <math.h>

//printf
#include <stdio.h>

#define WIN_WIDTH 1024
#define WIN_HEIGHT 512
#define WIN_RATIO 2.f

#define IMG_WIDTH 1024
#define IMG_HEIGHT 512

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_image;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// RAY
typedef struct s_ray
{
	t_vector3	origin;
	t_vector3	direction;
}	t_ray;


int	hit_sphere(t_ray ray, t_vector3 center, double radius)
{
	t_vector3	c_a;
	double		a;
	double		b;
	double		c;

	c_a = subtract_vector3(ray.origin, center);

	a = dot_product_vector3(ray.direction, ray.direction);
	b = 2.0 * dot_product_vector3(c_a, ray.direction);
	c = dot_product_vector3(c_a, c_a) - radius * radius;

	if (b * b - 4 * a * c > 0)
		return (1);
	else
		return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_image	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	img.img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
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


	t_ray		ray;
	t_vector3	unit_direction;

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			t_vector3 pixel_center;

			pixel_center = add_vector3(top_left_pixel, get_vector3(i * pixel_delta_x, j * pixel_delta_y, 0));
			ray.origin = get_vector3(0, 0, 0); // camera center;
			ray.direction = subtract_vector3(pixel_center, get_vector3(0, 0, 0));
			unit_direction = get_unit_vector3(ray.direction);

			//printf("%f, %f %f\n", ray.direction.x, ray.direction.y, ray.direction.z);

			t_vector3	color;
			double		a;

			a = 0.5 * (unit_direction.y + 1.0);
			color = add_vector3(get_vector3(1 - a, 1 - a, 1 - a), get_vector3(0.5 * a, 0.7 * a, 1.0 * a));

			int c = ((int)(color.x * 255) << 16) | ((int)(color.y * 255) << 8) | ((int)(color.z * 255));

			if (hit_sphere(ray, get_vector3(0, 0, -1.0), 0.5))
			{
				c = 0xFF0000;
			}
			my_mlx_pixel_put(&img, i, j, c);
		}
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
	return (0);
}


