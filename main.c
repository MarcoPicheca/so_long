#include "so_long.h"

/*
 * TODO: 
 * Inizializzazione mlx e della finestra di gioco.
 *
 * Creazione Xpm e degli sprite.
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
	return (0);
}
