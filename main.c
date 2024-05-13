#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Invalid argument\n"));
	map = (t_map){0};
	args_check(av[1]);
	if (square_char_check(av[1], &map) ||
		map.columns == map.lines || check_components(av[1], &map))
	{
		ft_printf("problems creating the map\n");
		ft_printf("cols %d, lines %d\n", map.columns, map.lines);
		return(0);
	}
	ft_printf("cols %d, lines %d\n", map.columns, map.lines);
	return (0);
}