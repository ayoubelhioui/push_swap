/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:35:16 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/02/02 19:19:00 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*to_the_last(t_stack **head_a)
{
	t_stack	*temp;

	temp = (*head_a);
	while (temp ->next)
		temp = temp ->next;
	return (temp);
}

void	just_for_25_lines_1(t_variables *var)
{
	var->last = var->last->previous;
	var->temp = var->temp->next;
	var->rotation_counter += 1;
}

void	initialization(t_stack **head_a, t_variables *var)
{
	var->temp = (*head_a);
	var->last = to_the_last(head_a);
	var->rotation_counter = 0;
}

void	a_to_b_helper(t_stack **head_a, t_stack **head_b, t_variables *var)
{
	multiple_rotations_a(head_a, head_b, var->rotation_counter, var->direction);
	if ((*head_b)->index < var->med)
		ft_rb(head_b, 1);
	var->rotation_counter = 0;
}

void	sort_four(t_stack **head_a, t_stack **head_b)
{
	int		min;
	int		position;

	min = find_min(head_a);
	position = is_exist(head_a, min);
	if (position > (FOUR / 2))
		multiple_rotations_a(head_a, \
				head_b, (FOUR - position) - 1, REVERSE_ROTATE);
	else
		multiple_rotations_a(head_a, head_b, position, ROTATE);
	sort_trio(head_a);
	ft_pa(head_a, head_b, 1);
}
