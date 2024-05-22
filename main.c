#include "so_long.h"

/*
 * TODO: 
 * - check sul personaggio contorni x + 1, x - 1, 
 * 		y + 1, y - 1
 * - check sull'uscita contorni x + 1, x - 1, 
 * 		y + 1, y - 1
 * - check su linee e colonne della mappa che non
 * 		possono essere tutte composte da 1 tranne
 * 		le prime e le ultime.
 * 		NB. controlla nel subject che ammenochè non
 * 		separino coll o exit o pers dal resto se possono esserci
 * 		ex.
 * 		111111111111
 * 		111111111111	corretta o no?
 * 		1000000000P1
 * 		1E0000000C01
 * 		111111111111
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