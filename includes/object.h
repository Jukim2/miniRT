/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:45:23 by kjs               #+#    #+#             */
/*   Updated: 2023/10/01 19:41:25 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_ambient_light
{
	float	light_ratio;
	int		rgb[3];
} t_ambient_light;

typedef struct s_camera
{
	float	coord[3];
	float	forward_vector[3];
	float	fov;
	// Not sure fov is float or int
} t_camera;

typedef struct s_light
{
	float	coord[3];
	float	light_ratio;
	int		rgb[3];
} t_light;

typedef struct s_sphere
{
	struct s_sphere	*next;
	float			coord[3];
	float			diameter;
	int				rgb[3];
} t_sphere;

typedef struct s_plane
{
	struct s_plane	*next;
	float			coord[3];
	float			normal_vector[3];
	int				rgb[3];
} t_plane;

typedef struct s_cylinder
{
	struct s_cylinder	*next;
	float				coord[3];
	float				normal_vector[3];
	float				diameter;
	float				height;
	int					rgb[3];
} t_cylinder;

typedef struct s_object
{
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_light			light;
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
} t_object;

#endif