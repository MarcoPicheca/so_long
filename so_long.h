#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
// # include "./minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pers
{
	int		x;
	int		y;
	int		one;
}				t_pers;

typedef struct s_exit
{
	int		x;
	int		y;
	int		one;
}				t_exit;

typedef struct s_map
{
	char	**matrix;
	t_pers	*pers;
	t_exit	*exit;
	int		lines;
	int		columns;
	int		x;
	int		y;
	int		collect;
}				t_map;

int		check_components(char *str, t_map *map);
int		ft_is_ber(char *str, int len, char *ext);
int		args_check(char *str);
int		check_char_map(char *str, t_map *map);
int		square_char_check(char *str, t_map *map);
void	ft_free_matrix(t_map *map);
int		checker_map(t_map *map);
int		check_main_char(t_map *map);
int		check_exit(t_map *map);
int		len_lines(t_map *map);
void	add_value_exit(t_map *map, int i);
void	add_value_pers(t_map *map, int i);
int		check_border_up_right(t_map *map);
int		check_border_down_left(t_map *map);
char	**copy_map(t_map *map);
int		flood_fill(char **map, int p_x, int p_y);
void	fill_visit(char **map, int p_x, int p_y);
void	free_matrix(char **map);
void	print_map(char **matrix);

#endif