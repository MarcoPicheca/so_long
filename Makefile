NAME = so_long

SRC	= main.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a \

PRINTF = ft_printf/libftprintf.a \

CC = cc

CFLAGS = -Wall -Werror -Wextra

MLX =  -L ./minilibx -lmlx -lX11 -lXext

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
RED='\033[31m'
CURSIVE='\033[3m'

all : $(NAME)

$(NAME) : $(OBJ)
	@make -sC minilibx
	@make bonus -sC libft
	@make -sC ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(PRINTF) -o $(NAME)
	@echo $(GREEN) "SO_LONG COMPILED\n"

clean :
	@make clean -sC minilibx
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

.PHONY : all re fclean clean