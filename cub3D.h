/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:36:45 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/18 17:38:54 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# define S_C 50
# define S_P 7

typedef struct l_data
{
	double	p_x;
	double	p_y;
	void	*mlx;
	void	*mlx_win;
	void *img;
	char *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	th;
	char	*p[10];
	int		w;
	int		h;
	double		t[6];
}			t_data;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

int			key_hook(int keycode, t_data *cub);
void		draw_carre(int x, int y, t_data cub);
void		put_plyr(int x, int y, t_data cub, int clr);
double			ray_hor(t_data cub, double *t);
double			ray_ver(t_data cub, double *t);
int			ft_strlen(char *s);
void		rays(t_data cub, double *t, int clr,int i);
int	ft_check_d(t_data *cub);
int	ft_check_a(t_data *cub);
void	draw_line(t_point p1, t_point p2, t_data cub, int clr);
void	func_rays(t_data cub, int clr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double     dist_walls(t_data cub);
#endif