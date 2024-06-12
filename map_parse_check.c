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

void	print_map(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf(matrix[i]);
		ft_printf("\n");
		i++;
	}
}

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

/*
 * Controlla che i componenti di base siano di un numero corretto
 * e alloca lo spazio necessario per raccogliere la matrice della mappa che verrà 
 * salvata in map.matrix per altri controlli su bordo, contorni di P e di E
 * e dei vari collectible.
 * Salverà ogni linea componente della mappa in ogni linea della matrice
 * per poi inviare la matrice al controllo.
 * 
*/

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
		if (map->matrix[i][ft_strlen(map->matrix[i]) - 1] != '\n')
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

/*
 * conta le linee e manda sia alla funzione per il check
 * dei caratteri componenti la mappa che alla funzione che
 * genera la matrice necessaria per la mappa
*/
int		square_char_check(char *str, t_map *map)
{
	char	*matrix;
	int		fd;

	fd = open(str, O_RDONLY);
	matrix = get_next_line(fd);
	while (matrix)
	{
		if (matrix && check_char_map(matrix, map))
		{
			ft_printf("Wrong char in the map\n");
			return (free(matrix), close(fd), 1);
		}
		free(matrix);
		matrix = get_next_line(fd);
		map->lines++;
	}
	close(fd);
	if (matrix)
		free(matrix);
	if (map->pers->one != 1 || map->exit->one != 1 ||
		map->collect <= 0)
		return (ft_printf("Missed char\n"), 1);
	if (map->columns == map->lines)
		return (ft_printf("Square map\n"), 1);
	return(0);
}
