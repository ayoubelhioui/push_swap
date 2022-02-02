/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:38:00 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 16:33:25 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_for_errors(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				error_printing();
			j++;
		}
		i++;
	}
	check_for_duplicate(av);
}

void	check_for_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error_printing();
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack **head_a)
{
	t_stack	*temp;

	temp = (*head_a);
	while (temp->next)
	{
		if (temp->content > temp ->next ->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	multiple_rotations_b(t_stack **head_b, int rotation_number, int sign)
{
	if (sign == ROTATE)
	{
		while (rotation_number > 0)
		{
			ft_rb(head_b, 1);
			rotation_number--;
		}
	}
	else
	{
		while (rotation_number >= 0)
		{
			ft_rrb(head_b, 1);
			rotation_number--;
		}
	}
}

void	final_touch(t_stack **head_a)
{
	t_stack	*last;

	while ((*head_a)->index != 0)
		ft_rra(head_a, 1);
	last = to_the_last(head_a);
	last ->index = last->previous->index + 1;
}
