# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:13:59 by ael-hiou          #+#    #+#              #
#    Updated: 2022/02/01 12:55:51 by ael-hiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
CFLAGS = -Wextra -Werror -Wall
SRC = push_swap.c src/operations.c src/quick_sort.c src/ft_helper.c src/ft_helper1.c src/ft_helper2.c src/ft_helper3.c
BONUS = checker_bonus.c src/operations.c src/ft_helper.c includes/get_next_line.c includes/get_next_line_utils.c src/ft_helper2.c src/ft_helper3.c src/ft_helper1.c src/quick_sort.c
NAME = push_swap
BONUS_NAME = checker_bonus
LIBFT = libft/libft.a

all:$(NAME)
$(NAME):
		@cd libft && make && make bonus && cd ..
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
bonus:
		@cd libft && make && make bonus && cd ..
		@$(CC) $(CFLAGS) $(LIBFT) $(BONUS) -o $(BONUS_NAME)		
clean:
		@cd libft && make clean && cd ..
fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
re: fclean all