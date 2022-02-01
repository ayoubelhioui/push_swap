/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:00:20 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/02/01 17:32:12 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_stack **head_a, t_stack **head_b)
{
	int		number;
	t_stack	*last;

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

void	a_to_b(t_stack **head_a, t_stack **head_b, int min, int max)
{
	variables	var;

	initialization(head_a, &var.temp, &var.last, &var.rotation_counter);
	var.k = min;
	var.med = (max - min) / 2;
	while (var.k <= max)
	{
		if ((var.temp)->index >= min && (var.temp)->index <= max)
		{
			var.direction = ROTATE;
			a_to_b_helper(head_a, head_b, &var.rotation_counter, var);
			just_for_25_lines(head_a, &var.last, &var.temp, &var.k);
		}
		else if (var.last ->index >= min && var.last->index <= max)
		{
			var.direction = REVERSE_ROTATE;
			a_to_b_helper(head_a, head_b, &var.rotation_counter, var);
			just_for_25_lines(head_a, &var.last, &var.temp, &var.k);
		}
		else
			just_for_25_lines_1(&var.temp, &var.last, &var.rotation_counter);
	}
}

void	push_swap_helper(t_stack **head_a, t_stack **head_b, int size)
{
	t_stack	*min;
	int		to_be_pushed;
	int		max;

	while (size > 5)
	{
		to_be_pushed = (size - 5) / 4 + 1;
		min = find_min(head_a);
		max = min->index + (to_be_pushed - 1);
		a_to_b(head_a, head_b, min->index, max);
		size -= to_be_pushed;
	}
	sort_five(head_a, head_b);
	b_to_a(head_a, head_b);
	final_touch(head_a);
}

void	push_swap(t_stack **head_a, t_stack **head_b)
{
	int	size;

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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || ac == 2)
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
	while (stack_a)
	{
		printf("Stack A : %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("------------\n");
	while (stack_b)
	{
		printf("Stack A : %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
}
