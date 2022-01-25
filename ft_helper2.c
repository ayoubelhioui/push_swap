/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:35:46 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 12:35:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    is_exist(t_stack **head, int value)
{
    t_stack *temp;
    int i;

    i = 0;
    temp = (*head);
    while (temp)
    {
        if (temp->index == value)
            return (i);
        temp = temp->next;
        i++;
    }
    return (-1);
}

void multiple_rotations_a(t_stack **head_a, t_stack **head_b,int rotation_number, int sign)
{
    if (sign == ROTATE)
    {
        while (rotation_number > 0)
        {
            ft_ra(head_a);
            rotation_number--;
        }
    }
    else
    {
        while (rotation_number >= 0)
        {
            ft_rra(head_a);
            rotation_number--;
        } 
    }
    ft_pb(head_a, head_b);

}

t_stack *find_min(t_stack **head_a)
{
    t_stack *temp;
    t_stack *min;

    temp = (*head_a);
    min = temp;
    while (temp)
    {
        if (min->index > (temp)->index)
            min = temp;
        temp = temp->next;
    }
    return (min);
}

void    sort_five(t_stack **head_a, t_stack **head_b)
{
    int i;
    t_stack *min;
    int position;
    int five;

    i = 0;
    five = 5;
    while (i < 2)
    {
        min = find_min(head_a);
        position = is_exist(head_a, min->index);
        if (position > (five / 2))
            multiple_rotations_a(head_a, head_b,(five - position) - 1, REVERSE_ROTATE);
        else
            multiple_rotations_a(head_a, head_b, position, ROTATE);
        five--;
        i++;
    }
    sort_trio(head_a);
    ft_pa(head_a, head_b);
    ft_pa(head_a, head_b);
}

void    change_value(t_stack **head_a)
{
    t_stack *temp;

    temp = (*head_a);
    while (temp->next)
        temp = temp->next;
    temp ->index = -1;
}