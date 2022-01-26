/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:29:20 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 11:29:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void b_to_a_helper(t_stack **head_a, t_stack **head_b, int number, t_stack **last)
{
    int k;
    int size;

    size = ft_lstsize((*head_b));
    if ((*head_b)->index < (*head_a)->index && (*head_b)->index > (*last)->index)
    {
        ft_pa(head_a, head_b, 1);
        ft_ra(head_a, 1);
        (*last) = (*last)->next;
    }
    else
    {
        k = is_exist(head_b, number);
        if (k > (size / 2))
            multiple_rotations_b(head_b, (size - k) - 1, REVERSE_ROTATE);
        else
            multiple_rotations_b(head_b, k, ROTATE);
        ft_pa(head_a, head_b, 1);
    }
}

void    b_to_a(t_stack **head_a, t_stack **head_b)
{
    int number;
    t_stack *last;

    last = to_the_last(head_a);
    change_value(head_a);
    while ((*head_b))
    {
        number = (*head_a)->index - 1;
        if (number == (*head_b)->index)
            ft_pa(head_a, head_b, 1);
        else if (is_exist(head_b, number) != -1)
            b_to_a_helper(head_a, head_b, number, &last);
        else if (is_exist(head_b, number) == -1)
            ft_rra(head_a, 1);
    }
}

void    a_to_b_helper(t_stack **head_a, t_stack **head_b, int *rotation_counter, int med, int direction)
{
    multiple_rotations_a(head_a, head_b, *rotation_counter, direction);
    if ((*head_b)->index < med)
        ft_rb(head_b, 1);
    (*rotation_counter) = 0;
}

void    just_for_25_lines(t_stack **head_a, t_stack **last , t_stack **temp,int *k, int *rotation_counter)
{
    (*rotation_counter) = 0;
    *k+= 1;
    (*temp) = (*head_a);
    (*last) = to_the_last(head_a);
}

void just_for_25_lines_1(t_stack **temp, t_stack **last, int *rotate_counter, int *rrotate_counter)
{
    (*last) = (*last)->previous;
    (*temp) = (*temp)->next;
    (*rotate_counter)+= 1;
    (*rrotate_counter)+= 1;
}

void    a_to_b(t_stack **head_a, t_stack **head_b, int min, int max, int med)
{

    t_stack *last;
    t_stack *temp;
    int rotate_counter;
    int k;
    int rrotate_counter;

    temp = (*head_a);
    last = to_the_last(head_a);
    rotate_counter = 0;
    rrotate_counter = 0;
    k = min;
    while (k <= max)
    {
        if ((temp)->index >= min && (temp)->index <= max)
        {
            a_to_b_helper(head_a, head_b, &rotate_counter, med, ROTATE);
            just_for_25_lines(head_a, &last, &temp, &k, &rrotate_counter);
        }
        else if (last ->index >= min && last->index <= max)
        {
            a_to_b_helper(head_a, head_b, &rrotate_counter, med, REVERSE_ROTATE);
            just_for_25_lines(head_a, &last, &temp, &k, &rotate_counter);
        }
        else
            just_for_25_lines_1(&temp, &last, &rotate_counter, &rrotate_counter);
    }
}


void    sort_four(t_stack **head_a, t_stack **head_b)
{
    t_stack *min;
    int position;

    min = find_min(head_a);
    position = is_exist(head_a, min->index);
    if (position > (FOUR / 2))
        multiple_rotations_a(head_a, head_b,(FOUR - position) - 1,REVERSE_ROTATE);
    else
       multiple_rotations_a(head_a, head_b, position, ROTATE);
    sort_trio(head_a);
    ft_pa(head_a, head_b, 1);
}

void    push_swap_helper(t_stack **head_a, t_stack **head_b, int size)
{
    t_stack *min;
    int to_be_pushed;
    int max;
    int med;

    while (size > 5)
    {
        to_be_pushed = (size - 5) / 3 + 1;
        min = find_min(head_a);
        max = min->index + (to_be_pushed - 1);
        med = (max + min->index) / 2;
        a_to_b(head_a, head_b, min->index, max, med);
        size -= to_be_pushed;
    }
    sort_five(head_a, head_b);
    b_to_a(head_a, head_b);
    final_touch(head_a);
}

void    push_swap(t_stack **head_a, t_stack **head_b)
{
    int size;


    size = ft_lstsize((*head_a));
    change_values_to_indexes(head_a, size);
    if (size == 2)
    {
        if ((*head_a)->content > (*head_a)->next->content)
            ft_sa(head_a, 1);
    }
    else if (size == 3)
        sort_trio(head_a);
    else if (size == 4)
        sort_four(head_a, head_b);
    else if (size == 5)
        sort_five(head_a, head_b);
    else
        push_swap_helper(head_a, head_b, size);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1)
        exit(1);
    while (i < ac)
    {
        if (ft_atoi(av[i]) > MAX_INT || ft_atoi(av[i]) < MIN_INT)
        {
            printf("Error\n");
            exit(1);
        }
        push(&stack_a, ft_atoi(av[i++]));
    }
    check_for_errors(&stack_a, ac - 1);
    push_swap(&stack_a, &stack_b);
    // while (stack_a)
    // {
    //     printf("data of stack a : %d\n", stack_a->content);
    //     stack_a = stack_a->next;
    // }
    // printf("---------------\n");
    // while (stack_b)
    // {
    //     printf("data of stack b : %d\n", stack_b->content);
    //     stack_b = stack_b->next;
    // }
}
