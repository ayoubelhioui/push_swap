# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:13:59 by ael-hiou          #+#    #+#              #
#    Updated: 2022/01/25 12:41:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
CFLAGS = -Wextra -Werror -Wall  -g
SRC = push_swap.c operations.c quick_sort.c ft_helper.c ft_helper1.c ft_helper2.c ft_helper3.c
NAME = a.out
LIBFT = libft/libft.a

all:$(NAME)
$(NAME):
		@cd libft && make && make bonus && cd ..
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
clean:
		@cd libft && make clean && cd ..
fclean:clean
	@rm -f $(NAME)
re:fclean all