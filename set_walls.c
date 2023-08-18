/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:56:44 by kelmouto          #+#    #+#             */
/*   Updated: 2023/08/18 17:50:57 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double     dist_walls(t_data cub)
{
    double d_v;
    double  h;
    double v;
    h = cub.t[5];
    v = cub.t[2];
    d_v = fabs((cub.w / 2) * tan(M_PI / 6));
    if(h > v)
        d_v  = ceil(fabs((S_C * 320) / v )) * 2;  
    else
        d_v  = ceil(fabs((S_C * 320) / h )) * 2; 
    printf("---->%d\n", (int)d_v);
    return(d_v);    
}