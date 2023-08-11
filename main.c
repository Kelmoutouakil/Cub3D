/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:43:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/09 14:17:33 by kelmouto         ###   ########.fr       */
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
	p[i++] = strdup("1111111111111111");
	p[i++] = strdup("1000000000000001");
	p[i++] = strdup("1000111111000001");
	p[i++] = strdup("1000100000000001");
	p[i++] = strdup("1000100E00000001");
	p[i++] = strdup("1000000001000001");
	p[i++] = strdup("1000111111000001");
	p[i++] = strdup("1000000000000001");
	p[i++] = strdup("1111111111111111");
	p[i] = NULL;
}
int	main(void)
{
	int		i;
	int		j;
	t_data	cub;

	j = 0;
	i = 0;
	cub.th = 5 * M_PI / 3;
	cub.mlx = mlx_init();
	fill_map(cub.p);
	cub.w = ft_strlen(cub.p[0]) * S_C;
	cub.h = 450;
	cub.mlx_win = mlx_new_window(cub.mlx, cub.w, 450, "cub3d");
	while (cub.p[i])
	{
		j = 0;
		while (cub.p[i][j])
		{
			if (cub.p[i][j] == '1')
				draw_carre(j, i, cub);
			if (cub.p[i][j] == 'E' || cub.p[i][j] == 'W' || cub.p[i][j] == 'N'
				|| cub.p[i][j] == 'S')
			{
				cub.p_x = j * S_C + S_C / 2;
				cub.p_y = i * S_C + S_C / 2;
				put_plyr(cub.p_x, cub.p_y, cub, 0x00ff00);
			}
			j++;
		}
		i++;
	}
	mlx_hook(cub.mlx_win, 2, 0, key_hook, &cub);
	mlx_loop(cub.mlx);
}
