/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:55:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/06 15:51:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vec3.h"
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
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

double	hit_sphere(t_ray ray, t_vec3 center, double radius)
{
	t_vec3	c_a;
	double		a;
	double		b;
	double		c;
	double		d;

	c_a = subtract_vec3(ray.origin, center);
	a = dot_vec3(ray.direction, ray.direction);
	b = dot_vec3(c_a, ray.direction);
	c = dot_vec3(c_a, c_a) - radius * radius;
	d = b * b - a * c;
	if (d < 0)
		return (-1);
	else
		return ((-b - sqrt(d)) / a);
}

t_vec3	get_color_vec3(t_ray ray)
{
	t_vec3	color;
	t_vec3	center; // sphere
	double		radius;
	double		t;


	center = get_vec3(0, 0, -1);
	radius = 0.5;
	t = hit_sphere(ray, center, radius);
	if (t > 0.0)
	{


		t_vec3 light = get_vec3(1.0, 1.0, 0.0);
		t_vec3 light_color = get_vec3(1.0, 1.0, 1.0);


		// Origin + t * Direction : point on a sphere
		// point - center of a sphere : normal vector
		// so, unit{(origin + t * direction) - center}
		t_vec3 normal = get_unit_vec3(\
							subtract_vec3(\
								add_vec3(ray.origin, \
								multiple_vec3(t, ray.direction)), center));

		t_vec3 light_to = subtract_vec3(add_vec3(ray.origin, multiple_vec3(t, ray.direction)), light);
		double cosine = dot_product_vec3(get_unit_vec3(light_to), normal);
		double lambert = cosine; // max(cosine, 0)
		double distance = get_vec3_length(light_to);
		double luminosity = 1 / (1 + (distance * distance)); // for distance == 0
		double test = -luminosity * lambert;
		return (multiple_vec3(test, light_color));
		//return (multiple_vec3(0.5, add_vec3(normal, get_vec3(1, 1, 1))));
	}
	double a = 0.5 * (ray.direction.y + 1.0);
	color = add_vec3(get_vec3(1 - a, 1 - a, 1 - a), get_vec3(0.5 * a, 0.7 * a, 1.0 * a));
	return (color);
}

// convert (0, 0, 0) -> 0x000000
int	convert_color_vec3(t_vec3 color_vec3)
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

	t_vec3	top_left_pixel;
	top_left_pixel.x = -viewport_width / 2. + pixel_delta_x * 0.5;
	top_left_pixel.y = -viewport_height / 2. + pixel_delta_y * 0.5;
	top_left_pixel.z = -focal_length;

	t_vec3	pixel_center;
	t_ray		ray;

	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 512; j++)
		{

			pixel_center = add_vec3(top_left_pixel, get_vec3(i * pixel_delta_x, j * pixel_delta_y, 0));
			ray.origin = get_vec3(0, 0, 0); // camera center;
			ray.direction = subtract_vec3(pixel_center, get_vec3(0, 0, 0));
			ray.direction = get_unit_vec3(ray.direction); // get unit_vector

			t_vec3 color_vector = get_color_vec3(ray);
			int color = convert_color_vec3(color_vector);
			my_mlx_pixel_put(&img, i, 511 - j, color);
		} 
	}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
	return (0);
}


