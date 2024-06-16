/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_flood_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:45:58 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/16 18:02:08 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_visit(char **map, int p_x, int p_y)
{
	if (map[p_x][p_y] == 'V' || map[p_x][p_y] == '1')
		return ;
	map[p_x][p_y] = 'V';
	fill_visit(map, p_x + 1, p_y);
	fill_visit(map, p_x, p_y + 1);
	fill_visit(map, p_x - 1, p_y);
	fill_visit(map, p_x, p_y - 1);
}

int	flood_fill(char **map, int p_x, int p_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fill_visit(map, p_x, p_y);
	while (map[x + 1] != NULL)
	{
		while (map[x][y] != '\0')
		{
			if (map[x][y] != '1' &&
				map[x][y] != '0' &&
				map[x][y] != 'V')
				return (free_matrix(map), 1);
			else
				y++;
		}
		y = 0;
		x++;
	}
	return (free_matrix(map), 0);
}
