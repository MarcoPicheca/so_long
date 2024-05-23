#include "so_long.h"

/*
 * TODO: 
 * - controllo sulla raggiungibilità di ogni componente base
 * 		della mappa, quindi P deve poter raggiungere ogni C e
 * 		l'uscita
 * - creazione della memoria per i C e il puntatore a struct
 * 		che permetta di rintracciare la posix di ogni collectible
 * 	
 * 
*/

int	main(int ac, char **av)
{
	t_map	map;
	t_pers	pers;
	t_exit	exit;

	if (ac != 2)
		return (ft_printf("Invalid argument\n"));
	map = (t_map){0};
	pers = (t_pers){0};
	exit = (t_exit){0};
	map.pers = &pers;
	map.exit = &exit;
	args_check(av[1]);
	if (square_char_check(av[1], &map) ||
		map.columns == map.lines || check_components(av[1], &map))
	{
		ft_printf("problems creating the map, main\n");
		ft_printf("cols %d, lines %d\n", map.columns, map.lines);
		return(0);
	}
	ft_printf("cols %d, lines %d\n", map.columns, map.lines);
	return (0);
}
