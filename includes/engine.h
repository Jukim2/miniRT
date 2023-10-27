/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:17:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/27 22:44:19 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "mlx.h"
# include "object.h"
# include "quat.h"

# define WIN_W 2048
# define WIN_H 1024

struct s_image earth;
struct s_image earth_bump;

enum e_display
{
	WD = 0,
	HT = 1
};

/*
res			: resolution
vport		: viewport
px_dt		: pixel_delta
ar			: aspect_ratio
bot_lt_px	: top_left_pixel
*/
typedef struct s_display
{
	int				res[2];
	double			vport[2];
	double			px_dt[2];
	double			ar;
	t_vec3			bot_lt_px;
}	t_display;

/*
bpp		: bits_per_pixel
*/

typedef struct s_image
{
	void			*ptr;
	unsigned int	*addr;
	int				bpp;
	int				line_len;
	int				endian;
}	t_image;

typedef struct s_engine
{
	void		*mlx;
	void		*win;
	t_display	display;
	t_image		img;
	t_objects	objs;
}	t_engine;

int		init_engine(t_engine *e, char *conf);
void	execute_engine(t_engine *e);

#endif