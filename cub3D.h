/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:36:45 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 17:57:44 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define S_C 50
# define S_P 7

typedef struct l_data
{
	double	p_x;
	double	p_y;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	th;
	char	*p[10];
	int		w;
	int		h;
	double	t[6];
	double	ang;
	int		c;
	int		sol;
}			t_data;

/**********************raycasting***************************/
int			ft_strlen(char *s);
void		fill_map(char **p);
/**********************keyhook_utils************************/
int			ft_close(t_data *cub);
int			key_hook(int keycode, t_data *cub);
void		w_a_key_conditions(int keycode, t_data *cub);
void		min_keyhook(int keycode, t_data *cub);
/**********************chek_walls**************************/
double		dist_walls(t_data cub);
int			ft_check_d(t_data *cub);
int			ft_check_a(t_data *cub);
int			ft_check_wall1(t_data *cub);
int			ft_check_wall2(t_data *cub);
/**********************mlx_main_utils***********************/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init_ang(t_data *cub, int i, int j);
void		init_cub(t_data *cub);
void		init_mlx_func(t_data *cub);
/*********************rays_utils*****************************/
double		ray_hor(t_data cub);
double		ray_ver(t_data cub);
void		rays(t_data cub, int clr, int i);
void		func_rays(t_data cub, int clr);
void		limit_protec(t_data cub, double r_x, double r_y);
void		limit_prot_hor(t_data cub, double r_x, double r_y);
void		utils_w_v(t_data cub, int *i, int *j, double *d);
void		utils_w_h(t_data cub, int *i, int *j, double *d);

#endif