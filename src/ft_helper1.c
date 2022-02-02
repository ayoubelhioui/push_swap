/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:33:03 by marvin            #+#    #+#             */
/*   Updated: 2022/02/01 18:54:08 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **head, int value)
{
	t_stack	*newnode;

	newnode = ft_lstnew(value);
	ft_lstadd_back(head, newnode);
}

void	sort_trio(t_stack **head_a)
{
	if ((*head_a)->index < (*head_a)->next->index \
			&& (*head_a)->next->index < (*head_a)->next->next->index)
		return ;
	else if ((*head_a)->index < (*head_a)->next->index \
			&& (*head_a)->index < (*head_a)->next->next->index)
	{
		ft_sa(head_a, 1);
		ft_ra(head_a, 1);
	}
	else if ((*head_a)->index > (*head_a)->next->index \
			&& (*head_a)->index < (*head_a)->next->next->index)
		ft_sa(head_a, 1);
	else if ((*head_a)->index < (*head_a)->next->index \
			&& (*head_a)->index > (*head_a)->next->next->index)
		ft_rra(head_a, 1);
	else if ((*head_a)->index > (*head_a)->next->index \
			&& (*head_a)->next->index < (*head_a)->next->next->index)
		ft_ra(head_a, 1);
	else if ((*head_a)->index > (*head_a)->next->index \
			&& (*head_a)->next->index > (*head_a)->next->next->index)
	{
		ft_sa(head_a, 1);
		ft_rra(head_a, 1);
	}
}

int	get_index(int value, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (i);
}

int	*allocate(t_stack **head, int size)
{
	t_stack	*temp;
	int		*array;
	int		i;

	i = 0;
	array = malloc(sizeof(int) * size);
	temp = (*head);
	while (i < size && temp)
	{
		array[i++] = temp->content;
		temp = temp ->next;
	}
	quick_sort(array, 0, size - 1);
	return (array);
}

void	change_values_to_indexes(t_stack **head_a, int size)
{
	int		*array;
	t_stack	*temp;

	temp = (*head_a);
	array = allocate(head_a, size);
	while (temp)
	{
		temp ->index = get_index(temp->content, array, size);
		temp = temp->next;
	}
	free(array);
}
