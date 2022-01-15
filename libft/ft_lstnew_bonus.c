/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:44:48 by ael-hiou          #+#    #+#             */
/*   Updated: 2021/12/22 19:26:09 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_stack	*ft_lstnew(int content)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
