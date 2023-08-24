/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:36:06 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/24 17:47:07 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_close(t_data *cub)
{
	(void)cub;
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->w && y >= 0 && y < data->h)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
			/ 8));
		*(unsigned int *)dst = color;
	}
}

void	init_ang(t_data *cub, int i, int j)
{
	if (cub->p[i][j] == 'N')
		cub->th = 3 * M_PI / 2;
	if (cub->p[i][j] == 'S')
		cub->th = M_PI / 2;
	if (cub->p[i][j] == 'E')
		cub->th = 0;
	if (cub->p[i][j] == 'W')
		cub->th = M_PI;
}

void	init_cub(t_data *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->p[i])
	{
		j = 0;
		while (cub->p[i][j])
		{
			if (cub->p[i][j] == 'E' || cub->p[i][j] == 'W'
				|| cub->p[i][j] == 'N' || cub->p[i][j] == 'S')
			{
				init_ang(cub, i, j);
				cub->p_x = j * S_C + S_C / 2;
				cub->p_y = i * S_C + S_C / 2;
			}
			j++;
		}
		i++;
	}
}

void	init_mlx_func(t_data *cub)
{
	cub->mlx = mlx_init();
	fill_map(cub->p);
	cub->w = ft_strlen(cub->p[0]) * S_C;
	cub->h = 450;
	cub->mlx_win = mlx_new_window(cub->mlx, cub->w, 450, "cub3D");
	cub->img = mlx_new_image(cub->mlx, cub->w, cub->h);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, &cub->line_length, &cub->endian);
	cub->im_g = mlx_xpm_file_to_image(cub->mlx,"./imgs/wall.xpm", &cub->w_tex, &cub->h_tex);
	if(!cub->im_g)
		exit(1);
	cub->ad = mlx_get_data_addr(cub->im_g, &cub->bit, &cub->ln, &cub->edn);
}
