/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:37:23 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/01/25 12:43:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define FOUR 4
#define ROTATE 1
#define REVERSE_ROTATE 0
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
void    ft_ss(t_stack **head_a, t_stack **head_b);
void    ft_sa(t_stack **head);
void    change_values_to_indexes(t_stack **head_a, int size);
int *allocate(t_stack **head, int size);
int    get_index(int value ,int *array, int size);
void    sort_trio(t_stack **head_a);
void    ft_pa(t_stack **head_a, t_stack **head_b);
int    is_exist(t_stack **head, int value);
void multiple_rotations_a(t_stack **head_a, t_stack **head_b,int rotation_number, int sign);
t_stack *find_min(t_stack **head_a);
void    sort_five(t_stack **head_a, t_stack **head_b);
void    change_value(t_stack **head_a);
void    final_touch(t_stack **head_a);
void    multiple_rotations_b(t_stack **head_b, int rotation_number, int sign);
t_stack *to_the_last(t_stack **head_a);
void    check_for_duplicate(t_stack **head_a, int size);
void    check_for_errors(t_stack **head_a, int size);
void    push(t_stack **head, int value);
int    is_sorted(t_stack **head_a);
int     *allocate(t_stack **head, int size);
void    quick_sort(int *a,int start, int end);
int     partition(int *a, int start, int end);
void    ft_swap(int *a, int *b);
#endif