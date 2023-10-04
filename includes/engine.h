/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:17:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/04 17:18:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "mlx.h"
# include "object.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

enum e_display
{
	WIDTH = 0,
	HEIGHT = 1
};

typedef struct s_display
{
	int			resolution[2];
	double		viewport[2];
	double		pixel_delta[2];
	double		aspect_ratio;
	t_vector3	top_left_pixel;
}	t_display;

typedef struct s_image
{
	void			*ptr;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_display	display;
	t_image		img;
	t_objects	objects;
}	t_engine;

int		init_engine(t_engine *engine, char *config);
void	execute_engine(t_engine *engine);

#endif