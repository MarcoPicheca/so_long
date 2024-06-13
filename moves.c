/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/01 19:53:02 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_game(t_map *map)
{
	map->flag_end = 1;
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->pers->x;
	y = map->pers->y;
	if (map->matrix[x][y - 1] == '1' ||
		(map->matrix[x][y - 1] == 'E' &&
		map->collect != 0))
		return ;
	else if (map->matrix[x][y - 1] == 'E' &&
		!map->collect)
		ft_win_game(map);
	else if (map->matrix[x][y - 1] == 'C' ||
		map->matrix[x][y - 1] == '0')
	{
		if (map->matrix[x][y - 1] == 'C')
			map->collect--;
		map->matrix[x][y - 1] = 'P';
		map->matrix[x][y] = '0';
	}
	map->pers->y--;
	images_to_wndw(map);
}


void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->pers->x;
	y = map->pers->y;
	if (map->matrix[x][y + 1] == '1' ||
		(map->matrix[x][y + 1] == 'E' &&
		map->collect != 0))
		return ;
	else if (map->matrix[x][y + 1] == 'E' &&
		!map->collect)
		ft_win_game(map);
	else if (map->matrix[x][y + 1] == 'C' ||
		map->matrix[x][y + 1] == '0')
	{
		if (map->matrix[x][y + 1] == 'C')
			map->collect--;
		map->matrix[x][y + 1] = 'P';
		map->matrix[x][y] = '0';
	}
	map->pers->y++;
	images_to_wndw(map);
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->pers->x;
	y = map->pers->y;
	if (map->matrix[x - 1][y] == '1' ||
		(map->matrix[x - 1][y] == 'E' &&
		map->collect != 0))
		return ;
	else if (map->matrix[x - 1][y] == 'E' &&
		!map->collect)
		ft_win_game(map);
	else if (map->matrix[x - 1][y] == 'C' ||
		map->matrix[x - 1][y] == '0')
	{
		if (map->matrix[x - 1][y] == 'C')
			map->collect--;
		map->matrix[x - 1][y] = 'P';
		map->matrix[x][y] = '0';
	}
	map->pers->x--;
	images_to_wndw(map);
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->pers->x;
	y = map->pers->y;
	if (map->matrix[x + 1][y] == '1' ||
		(map->matrix[x + 1][y] == 'E' &&
		map->collect != 0))
		return ;
	else if (map->matrix[x + 1][y] == 'E' &&
		!map->collect)
		ft_win_game(map);
	else if (map->matrix[x + 1][y] == 'C' ||
		map->matrix[x + 1][y] == '0')
	{
		if (map->matrix[x + 1][y] == 'C')
			map->collect--;
		map->matrix[x + 1][y] = 'P';
		map->matrix[x][y] = '0';
	}
	map->pers->x++;
	images_to_wndw(map);
}
