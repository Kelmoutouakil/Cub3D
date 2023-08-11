/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:36:45 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/09 11:32:07 by kelmouto         ###   ########.fr       */
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
# define S_C 50
# define S_P 7
typedef struct l_data
{
	double	p_x;
	double	p_y;
	void	*mlx;
	void	*mlx_win;
	double	th;
	char	*p[10];
	int		w;
	int		h;
	int		t[6];
}			t_data;

int			key_hook(int keycode, t_data *cub);
void		draw_carre(int x, int y, t_data cub);
void		put_plyr(int x, int y, t_data cub, int clr);
int			ray_hor(t_data cub, int *t);
int			ray_ver(t_data cub, int *t);
int			ft_strlen(char *s);
void		rays(t_data cub, int *t, int clr);
#endif