/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:38:00 by marvin            #+#    #+#             */
/*   Updated: 2022/02/01 19:11:47 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_for_errors(t_stack **head_a, int size)
{
	if (is_sorted(head_a) == 1)
		exit(1);
	check_for_duplicate(head_a, size);
}

void	check_for_duplicate(t_stack **head_a, int size)
{
	int	*array;
	int	i;
	int	j;

	i = 0;
	array = allocate(head_a, size);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				printf("Error\n");
				exit(1);
			}
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
