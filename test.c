/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/01 21:41:50 by gyoon            ###   ########.fr       */
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


double	hit_sphere(t_ray ray, t_vector3 center, double radius)
{
	t_vector3	c_a;
	double		a;
	double		b;
	double		c;
	double		d;

	c_a = subtract_vector3(ray.origin, center);
	a = dot_product_vector3(ray.direction, ray.direction);
	b = 2.0 * dot_product_vector3(c_a, ray.direction);
	c = dot_product_vector3(c_a, c_a) - radius * radius;
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	else
		return ((-b - sqrt(d)) / (2.0 * a));
}

t_vector3	get_color_vector3(t_ray ray)
{
	t_vector3	color;
	t_vector3	center; // sphere
	double		radius;
	double		t;


	center = get_vector3(0, 0, -1);
	radius = 0.5;
	t = hit_sphere(ray, center, radius);
	if (t > 0.0)
	{
		// Origin + t * Direction : point on a sphere
		// point - center of a sphere : normal vector
		// so, unit{(origin + t * direction) - center}
		t_vector3 normal = get_unit_vector3(\
							subtract_vector3(\
								add_vector3(ray.origin, \
								multiple_vector3(t, ray.direction)), center));
		return (multiple_vector3(0.5, add_vector3(normal, get_vector3(1, 1, 1))));
	}
	double a = 0.5 * (ray.direction.y + 1.0);
	color = add_vector3(get_vector3(1 - a, 1 - a, 1 - a), get_vector3(0.5 * a, 0.7 * a, 1.0 * a));
	return (color);
}

// convert (0, 0, 0) -> 0x000000
int	convert_color_vector3(t_vector3 color_vec3)
{
	return (((int)(color_vec3.x * 255) << 16) | \
			((int)(color_vec3.y * 255) << 8) | \
			((int)(color_vec3.z * 255)));
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

	t_vector3	pixel_center;
	t_ray		ray;

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 512; j++)
		{

			pixel_center = add_vector3(top_left_pixel, get_vector3(i * pixel_delta_x, j * pixel_delta_y, 0));
			ray.origin = get_vector3(0, 0, 0); // camera center;
			ray.direction = subtract_vector3(pixel_center, get_vector3(0, 0, 0));
			ray.direction = get_unit_vector3(ray.direction); // get unit_vector

			t_vector3 color_vector = get_color_vector3(ray);
			int color = convert_color_vector3(color_vector);
			my_mlx_pixel_put(&img, i, 511 - j, color);
		}
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
	return (0);
}


