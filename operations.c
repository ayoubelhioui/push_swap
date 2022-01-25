/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:58:30 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/01/24 23:20:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

void    ft_rb(t_stack **head)
{
    t_stack *top;

    if (!head || !(*head) || !(*head)->next)
        return ;
    top = (*head);
    (*head) = (*head)->next;
    top ->next = NULL;
    ft_lstadd_back(head, top);
    // ft_putstr("rb\n");
}

void    ft_sb(t_stack **head)
{
    t_stack *temp;
    int swap;
    
    if (!head || !(*head) || !(*head)->next)
        return ;
    temp = *head;
    temp = temp->next;
    swap = temp->content;
    temp ->content = (*head)->content;
    (*head)->content = swap;
    // ft_putstr("sb\n");
}

void    ft_pb(t_stack **head_a, t_stack **head_b)
{
    t_stack *top;

    if (!head_a || !(*head_a))
        return ; 
    top = (*head_a);
    (*head_a) = (*head_a)->next;
    ft_lstadd_front(head_b, top);
    // ft_putstr("pb\n");
}

void    ft_rr(t_stack **head_a, t_stack **head_b)
{
    ft_rb(head_b);
    ft_ra(head_a);
}

void    ft_rrb(t_stack **head)
{
    t_stack *last;
    t_stack *temp;

    if (!head || !(*head) || !(*head)->next)
        return ;
    temp = *head;
    while ((*head)->next)
    {
        if ((*head) ->next->next == NULL)
            break;
        (*head) = (*head)->next;
    }
    last = (*head) ->next;
    (*head)->next = NULL;
    (*head) = temp;
    ft_lstadd_front(head, last);
    // ft_putstr("rrb\n");
}

void    ft_rrr(t_stack **head_a, t_stack **head_b)
{
    ft_rrb(head_b);
    ft_rra(head_a);
}