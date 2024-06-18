/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:00:52 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/24 12:19:49 by mapichec         ###   ########.fr       */
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
		if (len != i)
			return (1);
		j++;
	}
	return (0);
}

int	check_border_up_right(t_map *map)
{
	while (map->y < (map->columns - 1))
	{
		if (map->matrix[map->x][map->y] != '1')
			return (1);
		map->y++;
	}
	while (map->x < (map->lines - 1))
	{
		if (map->matrix[map->x][map->y] != '1')
			return (1);
		map->x++;
	}
	return (0);
}

int	check_border_down_left(t_map *map)
{
	while (map->y > 0)
	{
		if (map->matrix[map->x][map->y] != '1')
			return (1);
		map->y--;
	}
	while (map->x > 0)
	{
		if (map->matrix[map->x][map->y] != '1')
			return (1);
		map->x--;
	}
	return (0);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)ft_calloc2((map->lines + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	copy[map->lines] = NULL;
	while (map->matrix[i] != NULL)
	{
		copy[i] = ft_strdup(map->matrix[i]);
		if (!copy[i])
			return (free_matrix(copy), NULL);
		i++;
	}
	return (copy);
}

int	checker_map(t_map *map)
{
	char	**map_copy;

	map_copy = NULL;
	if (len_lines(map))
		return (1);
	if (check_border_up_right(map)
		|| check_border_down_left(map))
		return (1);
	if (check_main_char(map) || check_exit(map))
		return (1);
	map_copy = copy_map(map);
	if (!map_copy)
		return (1);
	if (flood_fill(map_copy, map->pers->x, map->pers->y))
		return (1);
	if (check_coll(map))
		return (1);
	return (0);
}
