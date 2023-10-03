
#define WIN_WIDTH 1024
#define WIN_HEIGHT 512
#define WIN_RATIO 2.f
#define IMG_WIDTH 1024
#define IMG_HEIGHT 512

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image;

#endif