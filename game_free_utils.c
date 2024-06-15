/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:49 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/01 19:54:56 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_free(t_map *map)
{
	free_window(map);
	exit(0);
	return (0);
}

void	free_sprites(t_map *map)
{
	if (map->badge)
		mlx_destroy_image(map->mlx_ptr, map->badge);
	if (map->wall)
		mlx_destroy_image(map->mlx_ptr, map->wall);
	if (map->floor)
		mlx_destroy_image(map->mlx_ptr, map->floor);
	if (map->exit->img_1)
		mlx_destroy_image(map->mlx_ptr, map->exit->img_1);
	if (map->exit->img_2)
		mlx_destroy_image(map->mlx_ptr, map->exit->img_2);
}

void	free_window(t_map *map)
{
	free_act(map);
	free_sprites(map);
	if (map->win_mlx)
		mlx_destroy_window(map->mlx_ptr, map->win_mlx);
	if (map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	if (map->matrix)
		ft_free_matrix(map);
	map = (t_map *){0};
	exit(0);
}

void	free_act(t_map *map)
{
	int	i;

	i = 0;
	if (!map->pers->act)
		return ;
	while (i < 7)
	{
		mlx_destroy_image(map->mlx_ptr, map->pers->act[i]);
		map->pers->act[i] = NULL;
		i++;
	}
	free(map->pers->act);
	map->pers->act = NULL;
}
