/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:00:52 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/24 11:50:54 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mem_matrix_fd(char *str, t_map *map)
{
	int	fd;

	fd = 0;
	if (map->exit->one != 1)
		return (-1);
	if (map->pers->one != 1)
		return (-1);
	map->matrix = (char **)ft_calloc(sizeof(char *), (map->lines + 1));
	if (!map->matrix)
		return (-1);
	fd = open(str, O_RDONLY);
	return (fd);
}

int	check_components(char *str, t_map *map)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	fd = mem_matrix_fd(str, map);
	if (fd < 0)
		return (1);
	while (i < map->lines)
	{
		map->matrix[i] = get_next_line(fd);
		if (!map->matrix[i])
			return (ft_free_matrix(map), close(fd), 1);
		if (map->matrix[i][ft_strlen(map->matrix[i]) - 1] != '\n' &&
			i < (map->lines - 1))
			return (ft_free_matrix(map), close(fd), 1);
		map->matrix[i] = ft_strtrim(map->matrix[i], "\n");
		i++;
	}
	map->matrix[i] = NULL;
	close(fd);
	if (checker_map(map))
		return (ft_free_matrix(map), 1);
	return (0);
}

int	check_char_map(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != 'P' && str[i] != '0'
			&& str[i] != 'E' && str[i] != '1'
			&& str[i] != 'C' && str[i] != '\n')
			return (1);
		if (str[i] == 'P')
			add_value_pers(map, i);
		if (str[i] == 'E')
			add_value_exit(map, i);
		if (str[i] == 'C')
			map->collect++;
		i++;
	}
	if (map->columns == 0 && i != 0)
		map->columns = --i;
	return (0);
}

int	square_char_check(char *str, t_map *map)
{
	char	*matrix;
	int		fd;

	fd = open(str, O_RDONLY);
	matrix = get_next_line(fd);
	while (matrix)
	{
		if (matrix && check_char_map(matrix, map))
			return (free(matrix), close(fd), 1);
		free(matrix);
		matrix = get_next_line(fd);
		map->lines++;
	}
	close(fd);
	if (matrix)
		free(matrix);
	if (map->pers->one != 1 || map->exit->one != 1
		|| map->collect <= 0)
		return (1);
	if (map->columns == map->lines)
		return (1);
	return (0);
}
