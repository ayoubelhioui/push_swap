/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:26:11 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 16:26:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void    checker_job(t_stack **head_a, t_stack **head_b)
{
    char    *saver;

    saver = get_next_line(0);
    while (saver)
    {
        if (ft_strncmp(saver, "pa\n",4) == 0)
            ft_pa(head_a, head_b, 0);
        else if (ft_strncmp(saver, "pb\n",3) == 0)
            ft_pb(head_a, head_b, 0);
        else if (ft_strncmp(saver, "sa\n", 3) == 0)
            ft_sa(head_a, 0);
        else if (ft_strncmp(saver, "sb\n", 3) == 0)
            ft_sb(head_b, 0);
        else if (ft_strncmp(saver, "ss\n", 3) == 0)
            ft_ss(head_a, head_b, 0);
        else if (ft_strncmp(saver, "ra\n", 3) == 0)
            ft_ra(head_a, 0);
        else if (ft_strncmp(saver, "rb\n", 3) == 0)
            ft_rb(head_b, 0);
        else if (ft_strncmp(saver, "rr\n", 3) == 0)
            ft_rr(head_a, head_b, 0);
        else if (ft_strncmp(saver, "rra\n", 4) == 0)
            ft_rra(head_a, 0);
        else if (ft_strncmp(saver, "rrb\n", 4) == 0)
            ft_rrb(head_b, 0);
        else if (ft_strncmp(saver, "rrr\n", 4) == 0)
            ft_rrr(head_a, head_b, 0);
        else
        {
            ft_putstr("Error\n");
            exit(1);
        }
        saver = get_next_line(0);
    }
    if (is_sorted(head_a) == 1)
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
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
    checker_job(&stack_a, &stack_b);
}