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
        return ;
    temp = *head;
    temp = temp->next;
    swap = temp->content;
    temp ->content = (*head)->content;
    (*head)->content = swap;
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
    return (array);
}

void    change_values_to_indexes(t_stack **head_a, int size)
{
    int *array;
    t_stack *temp;

    temp = (*head_a);
    
    array = ft_allocate_and_sort(head_a, size);
    while (temp)
    {
        temp ->index = get_index(temp->content, array, size);
        temp = temp->next;
    }
}

void    sort_five(t_stack **head_a, t_stack **head_b)
{
    int *array;
    array = ft_allocate_and_sort(head_a, 5);
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

void    a_to_b(t_stack **head_a, t_stack **head_b, int min, int max, int med)
{
    (void)med;
    t_stack *last;
    t_stack *temp;
    int rotate_counter;
    int a;
    int b;
    int rrotate_counter;
    
    rotate_counter = 0;
    a = 0;
    b = 0;
    rrotate_counter = 0;
    temp = (*head_a);
    last = (*head_a);
    while (last ->next)
        last = last->next;
    while (min <= max)
    {
        if ((temp)->content >= min || (temp)->content <= max)
        {
            while (rotate_counter > 0)
            {
                rotate_counter--;
                ft_ra(head_a);
            }
            ft_pb(&temp, head_b);
            min++;
            temp = (*head_a);
        }
        else if (last ->content >= min || last->content <= max)
        {
            while (rotate_counter > 0)
            {
                rrotate_counter--;
                ft_rra(head_a);
            }
            ft_pb(&temp, head_b);
            min++;
        }
        else
        {
            rrotate_counter++;
            rotate_counter++;
            temp = temp ->next;
            last = last->previous;
        }
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
            to_be_pushed = ((size - 5) / 3) + 1;
            max += to_be_pushed;
            med = (max + min) / 2;
            a_to_b(head_a, head_b, min, max, med);
            min = max;
            size -= to_be_pushed;
            u++;
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
    // push_swap(&stack_a, &stack_b);
    // sort_five(&stack_a, &stack_b);
    // printing(&stack_a);
    while (stack_a->next)
    {
        printf("data of stack a : %d\n", stack_a->content);
        stack_a = stack_a->next;
    }
    printf("---------------\n");
    while (stack_b)
    {
        printf("data of stack b : %d\n", stack_b->content);
        stack_b = stack_b->next;
    }
}