#include "so_long.h"

int	convert_pers(t_sprite *act, void *mlx_ptr)
{
	act->pers_0 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_0.xpm", 50, 50);
	act->pers_1 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_1.xpm", 50, 50);
	act->pers_2 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_2.xpm", 50, 50);
	act->pers_3 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_3.xpm", 50, 50);
	act->pers_4 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_4.xpm", 50, 50);
	act->pers_5 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_5.xpm", 50, 50);
	act->pers_6 = mlx_xpm_file_to_image(mlx_ptr, 
	"./pers/pers_6.xpm", 50, 50);
	if (!act->pers_0 || !act->pers_1 ||
		!act->pers_2 || !act->pers_3 ||
		!act->pers_4 || !act->pers_5 ||
		!act->pers_6)
		return (1);
}

int	convert_sprites(t_map *map)
{
	map->badge = mlx_xpm_file_to_image(map->mlx_ptr,
	"./textures/collect.xpm", 50, 50);
	map->floor = mlx_xpm_file_to_image(map->mlx_ptr,
	"./textures/floor.xpm", 50, 50);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr,
	"./textures/wall.xpm", 50, 50);
	map->exit->img_1 = mlx_xpm_file_to_image(map->mlx_ptr,
	"./textures/exit.xpm", 50, 50);
	map->exit->img_2 = mlx_xpm_file_to_image(map->mlx_ptr,
	"./textures/exit_2.xpm", 50, 50);
	if (!map->badge || !map->floor ||
		!map->floor || !map->exit->img_1 ||
		!map->exit->img_2)
		return (1);
}

void	*game_start(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (free_matrix(map->matrix), NULL);
	if (convert_sprite(map))
		return (free_window(map), NULL);
	map->win_mlx = mlx_new_window(map->mlx_ptr,
		(50 * map->columns), (50 * map->lines), "so_long");
	if (!map->win_mlx)
		return (free_window(map), NULL);
	images_to_wndw(map);
	mlx_hook(map->win_mlx, 17, 1L<<17, exit_free, map);
	mlx_loop_hook(map->mlx_ptr, loop_player, map);
	mlx_loop(map->mlx_ptr);
	return (NULL);
}

/*
 * TODO: 
 * tutto da provare
 * 
 * creare i key press
 * 
 * creare loop di gioco per le mosse del player e i vari eventi
 * 
 * 
*/

int	main(int ac, char **av)
{
	t_map		map;
	t_pers		pers;
	t_exit		exit;
	t_sprite	sprite;

	if (ac != 2)
		return (ft_prpersintf("Error\nInvalid argument\n"));
	map = (t_map){0};
	pers = (t_pers){0};
	exit = (t_exit){0};
	sprite = (t_sprite){0};
	map.pers = &pers;
	map.exit = &exit;
	map.pers->act = &sprite;
	args_check(av[1]);
	if (square_char_check(av[1], &map) ||
		check_components(av[1], &map))
		return(ft_printf("Error\nproblems in the map\n"), 0);
	if (!game_start(&map))
		return(ft_printf("Error\nproblems with Xserver\n"), 0);
	return (0);
}
