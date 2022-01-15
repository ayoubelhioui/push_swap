/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:19:11 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 15:19:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
int    partition(int *a, int start, int end)
{
    int i = start + 1;
    int j = start + 1;
    int pivot = a[start];
    while (j <= end)
    {
        if (a[j] <= pivot)
        {
            ft_swap(&a[i], &a[j]);
            i++;
        }
        j++;
    }
   ft_swap (&a[start], &a[i - 1]);
   return (i-1);
}

void    quick_sort(int *a,int start, int end)
{
    int i;
    if (end  < start)
      return;
    i = partition(a, start, end);
    quick_sort(a, start, i - 1);
    quick_sort(a, i + 1, end);
}