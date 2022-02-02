/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:38:13 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/02/02 17:06:23 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	just_for_25_lines(t_stack **head_a, t_stack **last, \
		t_stack **temp, int *k)
{
	*k += 1;
	(*temp) = (*head_a);
	(*last) = to_the_last(head_a);
}

void	b_to_a_helper(t_stack **head_a, \
		t_stack **head_b, int number, t_stack **last)
{
	int	k;
	int	size;

	size = ft_lstsize((*head_b));
	if ((*head_b)->index < (*head_a)->index && \
			(*head_b)->index > (*last)->index)
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_rrr(t_stack **head_a, t_stack **head_b, int print_or_non)
{
	ft_rrb(head_b, print_or_non);
	ft_rra(head_a, print_or_non);
}

void	error_printing(void)
{
	ft_putstr("Error\n");
	exit(1);
}
