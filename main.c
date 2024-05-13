#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Invalid argument\n"));
	map = (t_map){0};
	args_check(av[1]);
	if (count_lines(av[1], &map))
	{
		return(ft_printf("\nproblems creating the map\n"));
	}
	return (0);
}