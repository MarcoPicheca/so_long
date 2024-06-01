/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/01 19:53:02 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: conditional jump ma da capire

void	ft_free_matrix(t_map *map)
{
	int	i;

	i = 0;
	if (!map->matrix)
		return ;
	while (map->matrix[i] != NULL)
	{
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
	map = (t_map *){0};
	ft_printf("Matrix free 1\n");
}

void	free_sprites_p(t_sprite *act, void *mlx_ptr)
{
	if (act->pers_0)
		mlx_destroy_image(mlx_ptr, act->pers_0);
	if (act->pers_1)
		mlx_destroy_image(mlx_ptr, act->pers_0);
	if (act->pers_2)
		mlx_destroy_image(mlx_ptr, act->pers_0);
	if (act->pers_3)
		mlx_destroy_image(mlx_ptr, act->pers_0);
	if (act->pers_4)
		mlx_destroy_image(mlx_ptr, act->pers_0);
	if (act->pers_5)
		mlx_destroy_image(mlx_ptr, act->pers_0);
	if (act->pers_6)
		mlx_destroy_image(mlx_ptr, act->pers_0);
}

void	free_sprites(t_map *map)
{
	if (map->badge)
		mlx_destroy_image(map->mlx_ptr,
		map->badge);
	if (map->floor)
		mlx_destroy_image(map->mlx_ptr,
		map->floor);
	if (map->wall)
		mlx_destroy_image(map->mlx_ptr,
		map->wall);
	if (map->exit->img_1)
		mlx_destroy_image(map->mlx_ptr,
		map->exit->img_1);
	if (map->exit->img_2)
		mlx_destroy_image(map->mlx_ptr,
		map->exit->img_2);
}

void	exit_free(t_map *map)
{
	free_window(map);
	exit(0);
}

void	free_window(t_map *map)
{
	free_sprites_p(map->pers->act, map->mlx_ptr);
	free_sprites(map);
	if (map->win_mlx)
		mlx_destroy_window(map->mlx_ptr, map->win_mlx);
	if (map->mlx_ptr)
		mlx_destroy_display(map->mlx_ptr);
	if (map->matrix)
		free_matrix(map->matrix);
}

void	free_matrix(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
	ft_printf("Matrix free 2\n");
}
