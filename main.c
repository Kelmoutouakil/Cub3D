/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:43:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/19 15:39:56 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	fill_map(char **p)
{
	int	i;

	i = 0;
	p[i++] = strdup("1111111111111111111111111111111111111111");
	p[i++] = strdup("1000000000000000000000000000000000000001");
	p[i++] = strdup("1000000000000000000000000000000000000001");
	p[i++] = strdup("1001000000000000000000000000000000000011");
	p[i++] = strdup("1001000000000000000000000000000000001001");
	p[i++] = strdup("1011000000000000000000000000000000001001");
	p[i++] = strdup("1001000000000000000000000000000000001001");
	p[i++] = strdup("1000000N0000000000000N000000000000000001");
	p[i++] = strdup("1111111111111111111111111111111111111111");
	p[i] = NULL;
}

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

int	main(void)
{
	int		i;
	int		j;
	t_data	*cub;

	cub = malloc(sizeof(t_data));
	if (!cub)
		return (0);
	j = 0;
	i = 0;
	//cub->th = 3 * M_PI / 2;
	cub->mlx = mlx_init();
	fill_map(cub->p);
	cub->w = ft_strlen(cub->p[0]) * S_C;
	cub->h = 450;
	cub->mlx_win = mlx_new_window(cub->mlx, cub->w, 450, "cub3d");
	cub->img = mlx_new_image(cub->mlx, cub->w, cub->h);
	cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
		&cub->line_length, &cub->endian);
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
	mlx_hook(cub->mlx_win, 2, 3, key_hook, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close, cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	mlx_loop(cub->mlx);
}
