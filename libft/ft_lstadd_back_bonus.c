/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:05:56 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/22 19:27:16 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*save;

	if (!lst)
		return ;
	if (*lst)
	{
		save = ft_lstlast(*lst);
		save -> next = new;
		return ;
	}
	*lst = new;
}
