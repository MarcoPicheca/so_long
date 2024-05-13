#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
// # include "./minilibx-linux/mlx.h"
# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**matrix;
	int		lines;
	int		columns;
	int		x_size;
	int		y_size;
}				t_map;

int		ft_is_ber(char *str, int len, char *ext);
int		args_check(char *str);
int		check_char_map(char *str, t_map *map);
int		count_lines(char *str, t_map *map);

#endif