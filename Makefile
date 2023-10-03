NAME=cub3D
CC=gcc -g
FLAG=-Wall -Wextra -Werror
MLX= -I inc/minilibx -L inc/minilibx -lmlx -framework OpenGL -framework AppKit
LFT= -I inc/libft -L inc/libft -lft
SRC=$(wildcard *.c)

OBJ=$(SRC:.c=.o)

all: mlxinit libft $(OBJ) 
	$(CC) $(FLAG) $(OBJ) $(INC) $(MLX) $(LFT) -o $(NAME)

mlxinit:
	make -C inc/minilibx

libft:
	make extra -C inc/libft

clean:
	rm -rf $(OBJ) 

fclean: clean
	make clean -C inc/minilibx
	make fclean -C inc/libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean