#include "so_long.h"

int	ft_is_ber(char *str, int len, char *ext)
{
	int	i;

	i = 4;
	while (i > 0)
	{
		if (str[len] != ext[i])
			return (0);
		i--;
		len--;
	}
	return (1);
}

int args_check(char *str)
{
	int	i;
	int	fd;

	i = ft_strlen(str);
	fd = open(str, O_RDONLY | __O_DIRECTORY);
	if (!ft_is_ber(str, i, ".ber") || fd != -1)
	{
		ft_printf("Invalid file!\n");
		exit(1);
		return (1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Invalid open!\n");
		exit(2);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_char_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != 'P' && str[i] != '0'
			&& str[i] != 'E' && str[i] != '1'
			&& str[i] != 'C' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
 * conta le linee e manda sia alla funzione per il check
 * dei caratteri componenti la mappa che alla funzione che
 * genera la matrice necessaria per la mappa
*/
int		count_lines(char *str, t_map map)
{
	char	*matrix;
	int		lines;
	int		fd;

	lines = 0;
	fd = open(str, O_RDONLY);
	while (matrix)
	{
		matrix = get_next_line(fd);
		if (matrix && check_char_map(matrix))
			return (0);
		lines++;
		ft_printf("%s", matrix);
	}
	lines--;
	ft_printf("num linee %d\n", lines);
	if (!map.lines)
		return (0);
	close(fd);
	return(lines);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Invalid argument\n"));
	map.lines = 0;
	args_check(av[1]);
	count_lines(av[1], map);
	if (!map.lines)
		return(ft_printf("\nproblems creating the map\n"));
	return (0);
}