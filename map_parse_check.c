/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:00:52 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/12 19:24:38 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
int		count_lines(char *str, t_map *map)
{
	char	*matrix;
	int		fd;

	fd = open(str, O_RDONLY);
	map->columns = 0;
	matrix = get_next_line(fd);
	while (matrix)
	{
		if (matrix && check_char_map(matrix, map))
		{
			free(matrix);
			close(fd);
			return (1);
		}
		free(matrix);
		matrix = get_next_line(fd);
		map->lines++;
	}
	if (matrix)
		free(matrix);
	if (map->columns == map->lines)
		return (1);
	close(fd);
	return(0);
}