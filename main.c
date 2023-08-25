/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:43:33 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/25 12:26:31 by kelmouto         ###   ########.fr       */
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
	p[i++] = strdup("1000000000000001000000011000000000100001");
	p[i++] = strdup("1001000000001000000000000000000000E10011");
	p[i++] = strdup("1001000000000000100000000000000000101001");
	p[i++] = strdup("1011000000000000000000000000000000001001");
	p[i++] = strdup("1001000000000000000011100000000000001001");
	p[i++] = strdup("1000000000000000000000000000000000000001");
	p[i++] = strdup("1111111111111111111111111111111111111111");
	p[i] = NULL;
}

int	main(void)
{
	t_data	*cub;

	cub = malloc(sizeof(t_data));
	if (!cub)
		return (0);
	init_mlx_func(cub);
	init_cub(cub);
	cub->ang = cub->th;
	func_rays(*cub, 0x87CEFA);
	mlx_hook(cub->mlx_win, 2, 3, key_hook, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_close, cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
	mlx_loop(cub->mlx);
}
