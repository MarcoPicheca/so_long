/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/16 17:45:17 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_game(t_map *map, int j, int move)
{
	map->flag_end = 1;
	if (move == 1)
		ft_printf("move number %d left\n", j);
	if (move == 2)
		ft_printf("move number %d right\n", j);
	if (move == 3)
		ft_printf("move number %d up\n", j);
	if (move == 4)
		ft_printf("move number %d down\n", j);
}

void	move_left(t_map *map, int j)
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
		ft_win_game(map, j, 1);
	else if (map->matrix[x][y - 1] == 'C' ||
		map->matrix[x][y - 1] == '0')
	{
		if (map->matrix[x][y - 1] == 'C')
			map->collect--;
		map->matrix[x][y - 1] = 'P';
		map->matrix[x][y] = '0';
		ft_printf("moves number %d left\n", j);
	}
	map->pers->y--;
}

void	move_right(t_map *map, int j)
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
		ft_win_game(map, j, 2);
	else if (map->matrix[x][y + 1] == 'C' ||
		map->matrix[x][y + 1] == '0')
	{
		if (map->matrix[x][y + 1] == 'C')
			map->collect--;
		map->matrix[x][y + 1] = 'P';
		map->matrix[x][y] = '0';
		ft_printf("moves number %d right\n", j);
	}
	map->pers->y++;
}

void	move_up(t_map *map, int j)
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
		ft_win_game(map, j, 3);
	else if (map->matrix[x - 1][y] == 'C' ||
		map->matrix[x - 1][y] == '0')
	{
		if (map->matrix[x - 1][y] == 'C')
			map->collect--;
		map->matrix[x - 1][y] = 'P';
		map->matrix[x][y] = '0';
		ft_printf("moves number %d up\n", j);
	}
	map->pers->x--;
}

void	move_down(t_map *map, int j)
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
		ft_win_game(map, j, 4);
	else if (map->matrix[x + 1][y] == 'C' ||
		map->matrix[x + 1][y] == '0')
	{
		if (map->matrix[x + 1][y] == 'C')
			map->collect--;
		map->matrix[x + 1][y] = 'P';
		map->matrix[x][y] = '0';
		ft_printf("moves number %d down\n", j);
	}
	map->pers->x++;
}
