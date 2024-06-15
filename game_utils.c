/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:54:33 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/07 17:16:26 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delay_frame(int del)
{
	while (del > 0)
		del--;
}

int	loop_player(t_map *map)
{
	static int	i = 0;

	if (!map->flag_end)
	{
		if (i == 6)
			i = 0;
		put_image(map->mlx_ptr, map->win_mlx, map->pers->act[i],
			map->pers->y, map->pers->x);
		i++;
		delay_frame(DELAY);
	}
	return (0);
}

void	put_image(t_map *map, void *img, int j, int i)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_mlx, img,
		(50 * j), (50 * i));
}

void	images_to_wndw(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lines && !map->flag_end)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->matrix[i][j] == '1')
				put_image(map, map->wall, j, i);
			if (map->matrix[i][j] == '0')
				put_image(map, map->floor, j, i);
			if (map->matrix[i][j] == 'P')
				put_image(map, map->pers->act[0], j, i);
			if (map->matrix[i][j] == 'C')
				put_image(map, map->badge, j, i);
			if (map->matrix[i][j] == 'E' && map->collect != 0)
				put_image(map, map->exit->img_1, j, i);
			if (map->matrix[i][j] == 'E' && map->collect == 0)
				put_image(map, map->exit->img_2, j, i);
			j++;
		}
	}
}
