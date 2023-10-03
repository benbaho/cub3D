# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alperdemirci <alperdemirci@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 14:26:55 by ademirci          #+#    #+#              #
#    Updated: 2023/02/24 21:39:18 by alperdemirc      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -g -c
SRC = $(shell find ./mandatory -name "*.c")
BONUS = $(shell find ./bonus -name "*.c")
EXTRA = $(shell find ./extra -name "*.c")

all:
	@gcc $(FLAG) $(OPTION) $(SRC)
	@if [ -d "object" ]; then mv *.o ./object; else mkdir object; mv *.o ./object; fi
	@ar rc $(NAME) ./object/*.o

bonus: all
	@gcc $(FLAG) $(OPTION) $(BONUS)
	@mv *.o ./object
	@ar rc $(NAME) ./object/*.o

extra: all bonus
	@gcc $(FLAG) $(OPTION) $(EXTRA)
	@mv *.o ./object
	@ar rc $(NAME) ./object/*.o

clean:
	@rm -rf  object

fclean: clean
	@rm -rf $(NAME)

re: fclean all