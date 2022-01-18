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

void rotate_it(t_stack **head_a, t_stack **head_b, int rotation_number, int sign, int med)
{
    if (sign == 1)
    {
        // printf("R Is : %d\n", rotation_number);
        while (rotation_number > 0)
        {
            ft_ra(head_a);
            rotation_number--;
        }
        // printf("We Will Push : %d\n",(*head_a)->index);
    }
    else
    {
        // printf("R-1 : %d\n",rotation_number);
        while (rotation_number >= 0)
        {
            ft_rra(head_a);
            rotation_number--;
        } 
    }
    ft_pb(head_a, head_b);
    if ((*head_b)->index < med)
        ft_rb(head_b);
}
void    a_to_b(t_stack **head_a, t_stack **head_b, int min, int max, int med)
{

    t_stack *last;
    t_stack *temp;
    int rotate_counter;
    int k;
    int rrotate_counter;
    
    rotate_counter = 0;
    rrotate_counter = 0;
    temp = (*head_a);
    last = to_the_last(head_a);
    k = min;
    while (k <= max)
    {
        if ((temp)->index >= min && (temp)->index <= max)
        {
            rotate_it(head_a, head_b, rotate_counter, 1, med);
            rotate_counter = 0;
            k++;
            temp = (*head_a);
            last = to_the_last(head_a);
            rrotate_counter = 0;
        }
        else if (last ->index >= min && last->index <= max)
        {
            rotate_it(head_a, head_b, rrotate_counter, 0, med);
            rotate_counter = 0;
            k++;
            temp = (*head_a);
            last = to_the_last(head_a);
            rrotate_counter = 0;
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
    }
}

int    find_min(t_stack **head_a)
{
    t_stack *temp;
    int min;

    temp = (*head_a);
    min = temp->index;
    while (temp)
    {
        if (min > (temp)->index)
            min = temp->index;
        temp = temp->next;
    }
    return (min);
}

void    push_swap(t_stack **head_a, t_stack **head_b)
{
    int size;
    int to_be_pushed;
    int min;
    int max;
    int med;
    // int u;

    // u = 0;
    max = 0;
    min = 0;
    size = ft_lstsize((*head_a));
    (void)head_b;
    if (size == 3)
        sort_trio(head_a);
    else if (size > 5)
    {
        change_values_to_indexes(head_a, size);
        while (size > 5)
        {
            to_be_pushed = (size - 5) / 3 + 1;
            min = find_min(head_a);
            max = min + (to_be_pushed - 1);
            med = (max + min) / 2;
            a_to_b(head_a, head_b, min, max, med);
            size -= to_be_pushed; 
        }
        sort_five(head_a, head_b);
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
    // printf("Elements Is B : %d\n",x);
}