/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:51:55 by jbartosi          #+#    #+#             */
/*   Updated: 2023/07/12 18:58:27 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "Libft/libft.h"
# include "minilibx/mlx.h"

# define SCREENWIDTH 1280
# define SCREENHEIGHT 720
# define TEXTUREWIDTH 64
# define TEXTUREHEIGHT 64

typedef struct s_atof
{
	float	val;
	int		afterdot;
	float	scale;
	int		sign;
}				t_atof;

typedef struct s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldTime;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapY;
	int		mapX;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	prepWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		draw;
	double	frameTime;
	double	moveSpeed;
	double	rotSpeed;
	double	oldDirX;
	double	oldPlaneX;
	int		textNum;
	double	wallX;
	int		textX;
	int		textY;
	double	step;
	double	texPos;
}				t_info;

typedef struct s_image
{
	void			*img;
	unsigned char	*addr;
	int				bits_pp;
	int				line_len;
	int				endian;
}				t_image;

typedef struct s_box
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_image		*textures;
	char		**map;
	t_info		info;
	size_t		timer;
}				t_box;

int		exit_hook(t_box *box);
int		key_hook(int key, t_box *box);
void	parser(t_box *box, int fd);
void	redraw(t_box *box);

#endif
