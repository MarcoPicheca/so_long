/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:00:52 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/24 12:19:49 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_visit_c(char **map, int p_x, int p_y)
{
	if (map[p_x][p_y] == 'V' || map[p_x][p_y] == '1' || map[p_x][p_y] == 'E')
		return ;
	map[p_x][p_y] = 'V';
	fill_visit_c(map, p_x + 1, p_y);
	fill_visit_c(map, p_x, p_y + 1);
	fill_visit_c(map, p_x - 1, p_y);
	fill_visit_c(map, p_x, p_y - 1);
}

int	flood_fill_c(char **map, int c_x, int c_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fill_visit_c(map, c_x, c_y);
	while (map[x + 1] != NULL)
	{
		while (map[x][y] != '\0')
		{
			if (map[x][y] != '1' &&
				map[x][y] != '0' && map[x][y] != 'E' &&
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

int	check_coll(t_map *map)
{
	char	**map_copy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map_copy = NULL;
	while (map->matrix[x] && x < map->lines)
	{
		while (map->matrix[x][y] != '\0')
		{
			if (map->matrix[x][y] == 'C')
			{
				map_copy = copy_map(map);
				if (flood_fill_c(map_copy, x, y))
					return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
