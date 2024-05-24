/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pers_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/24 10:46:18 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_value_pers(t_map *map, int i)
{
	map->pers->one++;
	map->pers->y = i;
	map->pers->x = map->lines;
}

int	check_main_char(t_map *map)
{
	map->x = map->pers->x;
	map->y = map->pers->y;
	if (map->matrix[(map->x + 1)][map->y] == '1' &&
		map->matrix[(map->x - 1)][map->y] == '1' &&
		map->matrix[map->x][(map->y - 1)] == '1' &&
		map->matrix[map->x][(map->y + 1)] == '1')
		return (ft_printf("P can't move\n"), 1);
	map->x = 0;
	map->y = 0;
	return (0);
}
