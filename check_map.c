/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:00:52 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/12 19:24:38 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_lines(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = ft_strlen(map->matrix[0]);
	j = 1;
	while (j < map->lines)
	{
		len = ft_strlen(map->matrix[j]);
		ft_printf("ci sono %d E %d\n", i, len);
		if (len != i)
			return (1);
		j++;
	}
	return (0);
}

int	checker_map(t_map *map)
{
	if (len_lines(map))
	{
		ft_free_matrix(map);
		exit(0);
		return (1);
	}
	while (map->y < (map->columns - 1))
	{
		if (map->matrix[map->x][map->y] != '1')
			return (1);
		if (map->matrix[map->x][map->y] == '\n')
			break ;
		map->y++;
	}
	exit(0);
	while (map->x < map->lines)
	{
		if (map->matrix[map->x][map->y] != '1')
			return (1);
		map->x++;
	}
}