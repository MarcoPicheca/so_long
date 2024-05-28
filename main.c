#include "so_long.h"

void	*game_start(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (NULL);
	map->win_mlx = mlx_new_window(map->mlx_ptr, (WIN_SIZE * map->columns),
		(WIN_SIZE * map->lines), "so_long");
	if (!map->win_mlx)
	{
		mlx_destroy_display(map->mlx_ptr);
		return (NULL);
	}
	mlx_loop(map->mlx_ptr);
	return (NULL);
}

/*
 * TODO: 
 * 
 * Inizializzazione immagini e puntatori grafici dei componenti.
 * 
 * Assegnazione dei puntatori grfici alle variabili e strutture.
 * 
 * Immagini to window.
 * 
 * Inizio loop di gioco.
 * 
 * Key hook delle mosse del personaggio con intercambio delle immagini al 
 * movimento del main_char.
 * 
 * 
*/

int	main(int ac, char **av)
{
	t_map	map;
	t_pers	pers;
	t_exit	exit;

	if (ac != 2)
		return (ft_printf("Error\nInvalid argument\n"));
	map = (t_map){0};
	pers = (t_pers){0};
	exit = (t_exit){0};
	map.pers = &pers;
	map.exit = &exit;
	args_check(av[1]);
	if (square_char_check(av[1], &map) ||
		check_components(av[1], &map))
		return(ft_printf("Error\nproblems in the map\n"), 0);
	if (!game_start(&map))
		return(ft_printf("Error\nproblems with Xserver\n"), 0);
	return (0);
}
