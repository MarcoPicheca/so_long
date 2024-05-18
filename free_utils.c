/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/17 15:55:04 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: conditional jump ma da capire

void	ft_free_matrix(t_map *map)
{
	int	i;

	i = 0;
	// if (!matrix)
	// 	return ;
	while (map->matrix[i] != NULL)
	{
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
	map = (t_map *){0};
	ft_printf("Problems creating the map\n");
	exit(0);
}
