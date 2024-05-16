#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
// # include "./minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**matrix;
	int		lines;
	int		columns;
	int		x;
	int		y;
	int		main_char;
	int		game_exit;
	int		collect;
}				t_map;

int		check_components(char *str, t_map *map);
int		ft_is_ber(char *str, int len, char *ext);
int		args_check(char *str);
int		check_char_map(char *str, t_map *map);
int		square_char_check(char *str, t_map *map);
void	ft_free_matrix(t_map *map);
int		checker_map(t_map *map);

#endif