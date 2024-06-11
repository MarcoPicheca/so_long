/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/24 10:46:22 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_value_exit(t_map *map, int i)
{
	map->exit->one++;
	map->exit->y = i;
	map->exit->x = map->lines;
}

int	check_exit(t_map *map)
{
	map->x = map->exit->x;
	map->y = map->exit->y;
	if (map->matrix[(map->x + 1)][map->y] == '1' &&
		map->matrix[(map->x - 1)][map->y] == '1' &&
		map->matrix[map->x][(map->y - 1)] == '1' &&
		map->matrix[map->x][(map->y + 1)] == '1')
		return (ft_printf("E isn't reachable\n"), 1);
	else
	{
		map->y = 0;
		map->x = 0;
	}
	return (0);
}
