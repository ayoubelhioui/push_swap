/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:29:35 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/01/06 15:07:27 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst)
		return ;
	if (!*lst)
	{	
		*lst = new;
		new ->next = NULL;
	}
	else
	{
		temp = *lst;
		*lst = new;
		new -> next = temp;
	}
}
