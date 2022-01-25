/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:18:17 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/01/24 23:19:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#define MAX_INT 2147483647
typedef struct s_stack
{
	int				content;
	int 			index;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;
void	*ft_calloc(size_t count, size_t size);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *src);
long long		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
char	*ft_itoa(int c);
size_t	ft_strlen(const char *s);

#endif
