/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:37:23 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/01/16 18:32:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"
typedef struct c_list
{
    int chunk_length;
    struct c_list *next;
}              t_chunks;

void    ft_putstr(char *str);
void    ft_sb(t_stack **head);
void    ft_pa(t_stack **head_a, t_stack **head_b);
void    ft_pb(t_stack **head_a, t_stack **head_b);
void    ft_rb(t_stack **head);
void    ft_ra(t_stack **head);
void    ft_rr(t_stack **head_a, t_stack **head_b);
void    ft_rrr(t_stack **head_a, t_stack **head_b);
void    ft_rra(t_stack **head);
void    ft_rrb(t_stack **head);
int     *allocate(t_stack **head, int size);
void    quick_sort(int *a,int start, int end);
int     partition(int *a, int start, int end);
void    ft_swap(int *a, int *b);
#endif