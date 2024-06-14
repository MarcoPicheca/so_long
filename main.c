/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/01 19:53:02 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**convert_pers(void *mlx_ptr)
{
	int		i;
	void	**act;

	i = 50;
	act = (void **)ft_calloc(7, sizeof(void *));
	act[0] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_0.xpm", &i, &i);
	act[1] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_1.xpm", &i, &i);
	act[2] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_2.xpm", &i, &i);
	act[3] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_3.xpm", &i, &i);
	act[4] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_4.xpm", &i, &i);
	act[5] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_5.xpm", &i, &i);
	act[6] = mlx_xpm_file_to_image(mlx_ptr,
			"./pers/pers_6.xpm", &i, &i);
	return (act);
}

int	convert_sprites(t_map *map)
{
	int	i;

	i = 50;
	map->pers->act = convert_pers(map->mlx_ptr);
	if (!map->pers->act)
		return (1);
	map->badge = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/collect.xpm", &i, &i);
	map->floor = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/floor.xpm", &i, &i);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/wall.xpm", &i, &i);
	map->exit->img_1 = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/exit.xpm", &i, &i);
	map->exit->img_2 = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/exit_2.xpm", &i, &i);
	return (0);
}

int	key_hook(int key, t_map *map)
{
	static int	i = 0;

	i++;
	if (key == K_ESC)
		return (free_window(map), 0);
	if (key == K_A || key == K_LEFT)
		move_left(map);
	if (key == K_S || key == K_DOWN)
		move_down(map);
	if (key == K_D || key == K_RIGHT)
		move_right(map);
	if (key == K_W || key == K_UP)
		move_up(map);
	ft_printf("key hook %d, moves number %d\n", key, i);
	if (map->flag_end)
	{
		mlx_clear_window(map->mlx_ptr, map->win_mlx);
		mlx_string_put(map->mlx_ptr, map->win_mlx, (S_PUT_C * 50),
			(map->lines / 2 * 50), WHITE_HEX, "YOU WON!");
		mlx_string_put(map->mlx_ptr, map->win_mlx, ((S_PUT_C - 1) * 50),
			((map->lines - 1) * 50), WHITE_HEX, "Press x or ESC to exit");
	}
	return (0);
}

void	*game_start(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (free_matrix(map->matrix), NULL);
	if (convert_sprites(map))
		return (free_window(map), NULL);
	map->win_mlx = mlx_new_window(map->mlx_ptr,
			(50 * map->columns), (50 * map->lines), "so_long");
	if (!map->win_mlx)
		return (free_window(map), NULL);
	images_to_wndw(map);
	mlx_hook(map->win_mlx, 17, (1L << 17), exit_free, map);
	mlx_key_hook(map->win_mlx, *key_hook, map);
	mlx_loop_hook(map->mlx_ptr, loop_player, map);
	mlx_loop(map->mlx_ptr);
	return (NULL);
}

// TODO: NORMINETTAREEEEEEEE

int	main(int ac, char **av)
{
	t_map		map;
	t_pers		pers;
	t_exit		exit;

	if (ac != 2)
		return (ft_printf("Error\nInvalid argument\n"));
	map = (t_map){0};
	pers = (t_pers){0};
	exit = (t_exit){0};
	map.pers = &pers;
	map.exit = &exit;
	args_check(av[1]);
	if (square_char_check(av[1], &map) || check_components(av[1], &map))
		return (ft_printf("Error\nproblems in the map\n"), 0);
	if (game_start(&map))
		return (ft_printf("Error\nproblems with Xserver\n"), 0);
	return (0);
}
