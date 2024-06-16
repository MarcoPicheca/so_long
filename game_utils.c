/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:54:33 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/16 17:45:20 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_player(t_map *map)
{
	static int	i = 0;

	if (!map->flag_end)
	{
		if (i == 6)
			i = 0;
		put_image(map, map->pers->act[i],
			map->pers->y, map->pers->x);
		i++;
		usleep(99999);
	}
	return (0);
}

void	finish_game(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_mlx);
	mlx_string_put(map->mlx_ptr, map->win_mlx, (map->columns / 2 * 50),
		(map->lines / 2 * 50), WHITE_HEX, "YOU WON!");
	mlx_string_put(map->mlx_ptr, map->win_mlx,
		((map->columns / 2 - 1) * 50),
		((map->lines - 1) * 50), RED_HEX, "Press x or ESC to exit");
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
