# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:13:59 by ael-hiou          #+#    #+#              #
#    Updated: 2022/02/02 16:22:10 by ael-hiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
CFLAGS = -Wextra -Werror -Wall
SRC = push_swap.c src/operations.c src/quick_sort.c src/ft_helper.c src/ft_helper4.c src/ft_helper5.c \
src/ft_helper1.c src/ft_helper2.c src/ft_helper3.c libft/ft_strncmp.c libft/ft_lstnew_bonus.c libft/ft_atoi.c \
libft/ft_bzero.c libft/ft_calloc.c libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c \
libft/ft_lstlast_bonus.c libft/ft_lstsize_bonus.c
BONUS = checker_bonus.c src/operations.c src/ft_helper5.c src/ft_helper4.c src/ft_helper.c includes/get_next_line.c \
includes/get_next_line_utils.c src/ft_helper2.c src/ft_helper3.c src/ft_helper1.c src/quick_sort.c \
libft/ft_strncmp.c libft/ft_lstnew_bonus.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_itoa.c \
libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstlast_bonus.c \
libft/ft_lstsize_bonus.c
NAME = push_swap
BONUS_NAME = checker_bonus

all:$(NAME)
$(NAME): $(SRC)
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
bonus: $(SRC)
		@$(CC) $(CFLAGS) $(BONUS) -o $(BONUS_NAME)
fclean:
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
re: fclean all