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
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**matrix;

	if (ac != 2)
		return (ft_printf("Invalid argument\n"));
	fd = args_check(av[1]);
	if (gen_matrix(av[1], fd))
	return (0);
}