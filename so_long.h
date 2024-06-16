/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/06/01 19:53:02 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define RED_HEX 0xff0000
# define WHITE_HEX 0xffffff
# define DELAY 10000000
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_UP 65362
# define K_LEFT 65361
# define K_DOWN 65364
# define K_RIGHT 65363
# define K_ESC 65307

typedef struct s_pers
{
	int		x;
	int		y;
	int		one;
	void	**act;
}				t_pers;

typedef struct s_exit
{
	int		x;
	int		y;
	void	*img_1;
	void	*img_2;
	int		one;
}				t_exit;

typedef struct s_map
{
	char	**matrix;
	void	*mlx_ptr;
	void	*win_mlx;
	void	*floor;
	void	*wall;
	void	*badge;
	t_pers	*pers;
	t_exit	*exit;
	int		lines;
	int		columns;
	int		flag_end;
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
void	ft_free_matrix(t_map *map);	
void	free_matrix(char **map);
void	free_act(t_map *map);
void	free_window(t_map *map);
void	free_sprites(t_map *map);
void	*game_start(t_map *map);
void	images_to_wndw(t_map *map);
void	put_image(t_map *map, void *img, int j, int i);
int		exit_free(t_map *map);
int		loop_player(t_map *map);
void	**convert_pers(void *mlx_ptr);
int		convert_sprites(t_map *map);
void	move_left(t_map *map, int j);
void	move_right(t_map *map, int j);
void	move_up(t_map *map, int j);
void	move_down(t_map *map, int j);
void	finish_game(t_map *map);

#endif