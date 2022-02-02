/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:30:33 by marvin            #+#    #+#             */
/*   Updated: 2022/02/01 18:16:39 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack **head, int print_or_non)
{
	t_stack	*temp;
	int		swap;
	int		swap_content;

	if (!head || !(*head) || !(*head)->next)
		return ;
	temp = *head;
	temp = temp->next;
	swap = temp->index;
	temp ->index = (*head)->index;
	(*head)->index = swap;
	swap_content = temp->content;
	temp->content = (*head)->content;
	(*head)->content = swap_content;
	if (print_or_non == 1)
		ft_putstr("sa\n");
}

void	ft_ss(t_stack **head_a, t_stack **head_b, int print_or_non)
{
	ft_sa(head_a, print_or_non);
	ft_sb(head_b, print_or_non);
}

void	ft_rra(t_stack **head, int print_or_non)
{
	t_stack	*last;
	t_stack	*temp;

	if (!head || !(*head) || !(*head)->next)
		return ;
	temp = *head;
	while ((*head)->next)
	{
		if ((*head)->next->next == NULL)
			break ;
		(*head) = (*head)->next;
	}
	last = (*head)->next;
	(*head)->next = NULL;
	(*head) = temp;
	ft_lstadd_front(head, last);
	if (print_or_non == 1)
		ft_putstr("rra\n");
}

void	ft_ra(t_stack **head, int print_or_non)
{
	t_stack	*top;

	if (!head || !(*head) || !(*head)->next)
		return ;
	top = (*head);
	(*head) = (*head)->next;
	top ->next = NULL;
	ft_lstadd_back(head, top);
	if (print_or_non == 1)
		ft_putstr("ra\n");
}

void	ft_pa(t_stack **head_a, t_stack **head_b, int print_or_non)
{
	t_stack	*top;

	if (!head_b || !(*head_b))
		return ;
	top = (*head_b);
	(*head_b) = (*head_b)->next;
	ft_lstadd_front(head_a, top);
	if (print_or_non == 1)
		ft_putstr("pa\n");
}
