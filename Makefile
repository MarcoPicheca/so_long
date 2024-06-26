NAME = so_long

SRC	= main.c \
	  map_parse_check.c \
	  exit_check.c \
	  pers_check.c \
	  args_check.c \
	  free_utils.c \
	  check_map.c \
	  coll_check.c \
	  algo_flood_fill.c \
	  game_free_utils.c \
	  moves.c \
	  game_utils.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a \

PRINTF = ft_printf/libftprintf.a \

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

MLX =  -Lminilibx-linux -lmlx -lX11 -lXext

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
RED='\033[31m'
CURSIVE='\033[3m'

all : $(NAME)

$(NAME) : $(OBJ)
	@make -sC minilibx-linux
	@make bonus -sC libft
	@make -sC ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(PRINTF) -o $(NAME)
	@echo $(GREEN) "SO_LONG COMPILED\n"

download:
	@wget https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz
	@$(RM) minilibx-linux.tgz

clean :
	@make clean -sC minilibx-linux
# TODO:ricordati di mettere la riozione della cartella della mlx
	@make clean -sC libft
	@make clean -sC ft_printf
	@rm -rf $(OBJ)
	@echo $(YELLOW) "SO_LONG CLEAN\n"

fclean : clean
	@make fclean -sC libft
	@make fclean -sC ft_printf
	@rm -rf $(NAME)
	@echo $(RED) "SO_LONG FCLEAN\n" $(NONE)

re : fclean all

.PHONY : all re download fclean clean

.SILENT: