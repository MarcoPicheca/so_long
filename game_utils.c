/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:54:33 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/01 19:55:52 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_player(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_0, map->pers->x, map->pers->y);
	usleep(1000);
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_1, map->pers->x, map->pers->y);
	usleep(1000);
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_2, map->pers->x, map->pers->y);
	usleep(1000);
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_3, map->pers->x, map->pers->y);
	usleep(1000);
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_4, map->pers->x, map->pers->y);
	usleep(1000);
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_5, map->pers->x, map->pers->y);
	usleep(1000);
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx,
		map->pers->act->pers_6, map->pers->x, map->pers->y);
	usleep(1000);
}

void	put_image(void *mlx_ptr, void *win_mlx, void *img, int j, int i)
{
	mlx_put_image_to_window(mlx_ptr, win_mlx, img, j, i);
}

void	images_to_wndw(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->lines)
	{
		while (j < map->columns)
		{
			if (map->matrix[i][j] == '1')
				put_image(map->mlx_ptr, map->win_mlx, map->wall, j, i);
			if (map->matrix[i][j] == '0')
				put_image(map->mlx_ptr, map->win_mlx, map->wall, j, i);
			if (map->matrix[i][j] == 'P')
				put_image(map->mlx_ptr, map->win_mlx, map->wall, j, i);
			if (map->matrix[i][j] == 'C')
				put_image(map->mlx_ptr, map->win_mlx, map->wall, j, i);
			if (map->matrix[i][j] == 'E')
				put_image(map->mlx_ptr, map->win_mlx, map->wall, j, i);
			j++;
		}
		j = 0;
		i++;		
	}
}
