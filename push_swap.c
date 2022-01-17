/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:29:20 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 11:29:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(t_stack **head)
{
    t_stack *temp;
    int swap;
    
    if (!head || !(*head) || !(*head)->next)
    {
        return ;
    }
    temp = *head;
    temp = temp->next;
    swap = temp->index;
    temp ->index = (*head)->index;
    (*head)->index = swap;
    // ft_putstr("sa\n");
}

void    ft_ss(t_stack **head_a, t_stack **head_b)
{
    ft_sa(head_a);
    ft_sb(head_b);
}

void    ft_rra(t_stack **head)
{
    t_stack *last;
    t_stack *temp;

    if (!head || !(*head) || !(*head)->next)
        return ;
    temp = *head;
    while ((*head)->next)
    {
        if ((*head) ->next->next == NULL)
            break;
        (*head) = (*head)->next;
    }
    last = (*head) ->next;
    (*head)->next = NULL;
    (*head) = temp;
    ft_lstadd_front(head, last);
    // ft_putstr("rra\n");
}

void    ft_ra(t_stack **head)
{
    t_stack *top;
    if (!head || !(*head) || !(*head)->next)
        return ;

    top = (*head);
    (*head) = (*head)->next;
    top ->next = NULL;
    ft_lstadd_back(head, top);
    // ft_putstr("ra\n");
}

void    push(t_stack **head, int value)
{
    t_stack *newnode;
    
    newnode = ft_lstnew(value);
    ft_lstadd_back(head, newnode);
}

void    ft_pa(t_stack **head_a, t_stack **head_b)
{
    t_stack *top;

    if (!head_b || !(*head_b))
        return ;
    top = (*head_b);
    (*head_b) = (*head_b)->next;
    ft_lstadd_front(head_a,top);
    // ft_putstr("pa\n");
}
void    sort_trio(t_stack **head_a)
{
    if ((*head_a)->content < (*head_a)->next->content)
    {
        if ((*head_a)->next->content > (*head_a)->next->next->content)
        {
            printf("Im Here :)\n");
            ft_sa(head_a);
            ft_ra(head_a);
        }
    }
    else if ((((*head_a)->content > (*head_a)->next->content) && ((*head_a)->content < (*head_a)->next->next->content)))
        ft_sa(head_a);
    else if ((*head_a)->content > (*head_a)->next->content)
    {
        if ((*head_a)->next->content > (*head_a)->next->next->content)
        {
            ft_sa(head_a);
            ft_rra(head_a);
        }
        else if ((*head_a)->next->content < (*head_a)->next->next->content)
            ft_ra(head_a);

    }

}

int    get_index(int value ,int *array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (array[i] == value)
            return (i);
        i++;
    }
    return (i);

}
int *allocate(t_stack **head, int size)
{
    t_stack *temp;
    int *array;
    int i;
    
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

void    change_values_to_indexes(t_stack **head_a, int size)
{
    int *array;
    t_stack *temp;

    temp = (*head_a);
    
    array = allocate(head_a, size);
    while (temp)
    {
        temp ->index = get_index(temp->content, array, size);
        temp = temp->next;
    }
}

void    sort_five(t_stack **head_a, t_stack **head_b)
{
    int *array;
    array = allocate(head_a, 5);
    int i = 0;
    while (i < 2)
    {
        if (array[i] == (*head_a)->content)
        {
            i++;
            ft_pb(head_a, head_b);
        }
        else
            ft_ra(head_a);
    }
    sort_trio(head_a);
    ft_pa(head_a, head_b);
    ft_pa(head_a, head_b);
}

void    b_to_a(t_stack **head_a, t_stack **head_b)
{
    int size;

    size = ft_lstsize((*head_b));
    while (size > 0)
    {
        ft_pa(head_a, head_b);
        size--;
    }
}
t_stack *to_the_last(t_stack **head_a)
{
    t_stack *temp;

    temp = (*head_a);
    while (temp ->next)
        temp = temp ->next;
    return (temp);
}
void    a_to_b(t_stack **head_a, t_stack **head_b, int min, int max, int med)
{
    (void)head_b;
    t_stack *last;
    t_stack *temp;
    int rotate_counter;
    int k;
    int rrotate_counter;
    
    rotate_counter = 0;
    int u = 0;
    // int a = 0;
    rrotate_counter = 1;
    temp = (*head_a);
    last = to_the_last(head_a);
    k = min;
    while (k < max)
    {
            if (!last)
                return;
        if ((temp)->index >= min && (temp)->index < max)
        {
            // printf("The Number Of Rotation Is : %d And The Number We Will Push Is : %d\n",rotate_counter, temp->index);
            while (rotate_counter > 0)
            {
                rotate_counter--;
                ft_ra(head_a);
            }
            ft_pb(head_a, head_b);
            if (temp ->index < med)
                ft_rb(head_b);
            k++;
            temp = (*head_a);
            last = to_the_last(head_a);
        }
        else if (last ->index >= min && last->index < max)
        {
            // printf("The Number Of Rotation Is : %d And The Number We Will Push Is : %d\n",rrotate_counter, last->index);
             printf("the Min Is : %d And The Max Is : %d\n",min, max);
            while (rrotate_counter > 0)
            {
                rrotate_counter--;
                ft_rrb(head_a);
            }
            ft_pb(head_a, head_b);
            if (last->index < med)
                ft_rb(head_b);
            k++;
            temp = (*head_a);
            last = to_the_last(head_a);
        }
        else
        {
            rrotate_counter++;
            rotate_counter++;
            temp = temp ->next;
            last = last->previous;
        }
        // printf("The Rotation is : %d And the Rrotation %d\n", rotate_counter,rrotate_counter);
        // printf("The Temp Is : %d And The Last Is : %d And The Head Is : %d\n",(temp)->index, last->index, (*head_a)->index);
        u++;
    }
}

void    push_swap(t_stack **head_a, t_stack **head_b)
{
    int size;
    int to_be_pushed;
    int min;
    int max;
    int med;
    int u;

    u = 0;
    min = 0;
    max = 0;
    size = ft_lstsize((*head_a));
    (void)head_b;
    if (size == 3)
        sort_trio(head_a);
    else if (size > 5)
    {
        change_values_to_indexes(head_a, size);
        while (size > 5 && u < 4)
        {
            to_be_pushed = ((size - 5) / 3) + 1;
            max += to_be_pushed;
            med = (max + min) / 2;
            a_to_b(head_a, head_b, min, max, med);
            min = max;
            size -= to_be_pushed;
            u++;
        }
        // sort_five(head_a, head_b);
        // b_to_a(head_a, head_b);
    }
}

void    printing(t_stack **head_a)
{
    t_stack *temp;

    temp = (*head_a);
    while (temp)
    {
        printf("Elements Index Is : %d\n",temp->index);
        temp = temp->next;
    }
}
int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    while (i < ac)
        push(&stack_a, ft_atoi(av[i++]));
    i = 0;
    push_swap(&stack_a, &stack_b);
    while (stack_a)
    {
        printf("data of stack a : %d\n", stack_a->index);
        stack_a = stack_a->next;
    }
    printf("---------------\n");
    int x = 0;
    while (stack_b)
    {
        x++;
        printf("data of stack b : %d\n", stack_b->index);
        stack_b = stack_b->next;
    }
    printf("Elements Is B : %d\n",x);
}