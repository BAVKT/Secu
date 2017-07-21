# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/21 15:43:53 by vmercadi          #+#    #+#              #
#    Updated: 2017/07/21 16:00:49 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polybe

SRC = srcs/polybe.c srcs/display.c srcs/init.c

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

SRCO = $(SRC:%.c=%.o)

INCLUDES = includes

.PHONY: all re clean

all: $(NAME)

$(NAME):
	@make re -C libft/
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all
