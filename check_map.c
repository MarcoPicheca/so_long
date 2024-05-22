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

int	check_main_char(t_map *map)
{
	map->x = map->pers->x;
	map->y = map->pers->y;
	if (map)
}

int	checker_map(t_map *map)
{
	if (len_lines(map))
		return (ft_printf("wrong line lenght\n"), 1);
	if (check_border_up_right(map) ||
		check_border_down_left(map))
		return (ft_printf("Wrong borders\n") ,1);
	if (che_main_char(map) || check_exit(map))
		return (ft_printf("Problems in the story\n"));
	exit(0);
}