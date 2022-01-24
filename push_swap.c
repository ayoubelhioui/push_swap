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
    int swap_content;
    

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
    ft_putstr("sa\n");
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
    ft_putstr("rra\n");
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
    ft_putstr("ra\n");
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
    ft_putstr("pa\n");
}

void    sort_trio(t_stack **head_a)
{
    if ((*head_a)->index < (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
        return;
	else if ((*head_a)->index < (*head_a)->next->index && (*head_a)->index < (*head_a)->next->next->index)
	{
		ft_sa(head_a);
		ft_ra(head_a);
	}
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->index < (*head_a)->next->next->index)
		ft_sa(head_a);
	else if ((*head_a)->index < (*head_a)->next->index && (*head_a)->index > (*head_a)->next->next->index)
		ft_rra(head_a);
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
		ft_ra(head_a);
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index)
	{
		ft_sa(head_a);
		ft_rra(head_a);
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

int    is_exist(t_stack **head, int value)
{
    t_stack *temp;
    int i;

    i = 0;
    temp = (*head);
    while (temp)
    {
        if (temp->index == value)
            return (i);
        temp = temp->next;
        i++;
    }
    return (-1);
}

void multiple_rotations_a(t_stack **head_a, int rotation_number, int sign)
{
    if (sign == ROTATE)
    {
        while (rotation_number > 0)
        {
            ft_ra(head_a);
            rotation_number--;
        }
    }
    else
    {
        while (rotation_number >= 0)
        {
            ft_rra(head_a);
            rotation_number--;
        } 
    }

}

t_stack *find_min(t_stack **head_a)
{
    t_stack *temp;
    t_stack *min;

    temp = (*head_a);
    min = temp;
    while (temp)
    {
        if (min->index > (temp)->index)
            min = temp;
        temp = temp->next;
    }
    return (min);
}

void    sort_five(t_stack **head_a, t_stack **head_b)
{
    int i;
    t_stack *min;
    int position;
    int five;

    i = 0;
    five = 5;
    while (i < 2)
    {
        min = find_min(head_a);
        position = is_exist(head_a, min->index);
        if (position > (five / 2))
            multiple_rotations_a(head_a, (five - position) - 1, REVERSE_ROTATE);
        else
            multiple_rotations_a(head_a, position, ROTATE);
        five--;
        ft_pb(head_a, head_b);
        i++;
    }
    sort_trio(head_a);
    ft_pa(head_a, head_b);
    ft_pa(head_a, head_b);
}

void    change_value(t_stack **head_a)
{
    t_stack *temp;

    temp = (*head_a);
    while (temp->next)
        temp = temp->next;
    temp ->index = -1;
}

t_stack *to_the_last(t_stack **head_a)
{
    t_stack *temp;

    temp = (*head_a);
    while (temp ->next)
        temp = temp ->next;
    return (temp);
}

void    multiple_rotations_b(t_stack **head_b, int rotation_number, int sign)
{
    if (sign == ROTATE)
    {
        while (rotation_number > 0)
        {
            ft_rb(head_b);
            rotation_number--;
        }
    }
    else
    {
        while (rotation_number >= 0)
        {
            ft_rrb(head_b);
            rotation_number--;
        } 
    }
}

void    final_touch(t_stack **head_a)
{
    t_stack *last;

    while ((*head_a) ->index != 0)
        ft_rra(head_a);
    last = to_the_last(head_a);
    last ->index = last->previous->index + 1;
}

void    b_to_a(t_stack **head_a, t_stack **head_b)
{
    int number;
    t_stack *last;
    int size;

    change_value(head_a);
    last = to_the_last(head_a);
    int k = 0;
    int i = 0;
    while ((*head_b))
    {
        size = ft_lstsize((*head_b));
        number = (*head_a)->index - 1;
        if (number == (*head_b)->index)
            ft_pa(head_a, head_b);
        else if (is_exist(head_b, number) != -1)
        {
            if ((*head_b)->index < (*head_a)->index && (*head_b)->index > last->index)
            {
                ft_pa(head_a, head_b);
                ft_ra(head_a);
                last = last->next;
            }
            else
            {
                k = is_exist(head_b, number);
                if (k > (size / 2))
                    multiple_rotations_b(head_b, (size - k) - 1, REVERSE_ROTATE);
                else
                    multiple_rotations_b(head_b, k, ROTATE);
                ft_pa(head_a, head_b);
            }
        }
        else if (is_exist(head_b, number) == -1)
            ft_rra(head_a);
        i++;
    }
}

void    a_to_b(t_stack **head_a, t_stack **head_b, int min, int max, int med)
{

    t_stack *last;
    t_stack *temp;
    int rotate_counter;
    int k;
    int rrotate_counter;

    temp = (*head_a);
    last = to_the_last(head_a);
    rotate_counter = 0;
    rrotate_counter = 0;
    k = min;
    while (k <= max)
    {
        if ((temp)->index >= min && (temp)->index <= max)
        {
            multiple_rotations_a(head_a, rotate_counter, ROTATE);
            ft_pb(head_a, head_b);
            if ((*head_b)->index < med)
                 ft_rb(head_b);
            rotate_counter = 0;
            k++;
            temp = (*head_a);
            last = to_the_last(head_a);
            rrotate_counter = 0;
        }
        else if (last ->index >= min && last->index <= max)
        {
            multiple_rotations_a(head_a, rrotate_counter, REVERSE_ROTATE);
            ft_pb(head_a, head_b);
            if ((*head_b)->index < med)
                ft_rb(head_b);
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
    }
}

int    is_sorted(t_stack **head_a)
{
    t_stack *temp;

    temp = (*head_a);
    while (temp->next)
    {
        if (temp->content > temp ->next ->content)
            return (0);
        temp = temp->next;
    }
    return (1);
}

void    push_swap(t_stack **head_a, t_stack **head_b)
{
    int size;
    int to_be_pushed;
    t_stack *min;
    int max;
    int med;

    max = 0;
    size = ft_lstsize((*head_a));
    change_values_to_indexes(head_a, size);
    if (size == 3)
        sort_trio(head_a);
    else if (size >= 5)
    {
        while (size > 5)
        {
            to_be_pushed = (size - 5) / 3 + 1;
            min = find_min(head_a);
            max = min->index + (to_be_pushed - 1);
            med = (max + min->index) / 2;
            a_to_b(head_a, head_b, min->index, max, med);
            size -= to_be_pushed;
        }
        sort_five(head_a, head_b);
        b_to_a(head_a, head_b);
        final_touch(head_a);
    }
}

int   to_int(char *str)
{
	int			i;
	int			sign;
	int			saver;

	i = 0;
	saver = 0;
	sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
	while (str[i] >= 48 && str[i] <= 57)
	{
		saver = saver * 10 + (str[i] - '0');
		i++;
	}
	return (sign * saver);
}

void    check_for_duplicate(t_stack **head_a, int size)
{
    int *array;
    int i;

    i = 0;
    array = allocate(head_a, size);
    while (i < size)
    {
        // if (array[i] == array[i + 1])
        // {
        //     printf("Error\n");
        //     exit(1);
        // }
        printf("Fuck : %d\n",array[i]);
        i++;
    }

}
 
void    check_for_errors(t_stack **head_a, int size)
{
    (void)size;
    if (is_sorted(head_a) == 1)
    {
        printf("Error\n");
        exit(1);
    }
    // check_for_duplicate(head_a, size);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1)
        exit(1);
    while (i < ac)
    {
        if (ft_atoi(av[i]) == -2147483648)
        {
            printf("Error\n");
            exit(1);
        }
        push(&stack_a, ft_atoi(av[i++]));
    }
    i = 0;
    // check_for_errors(&stack_a, ac - 1);
    push_swap(&stack_a, &stack_b);
    // while (stack_a)
    // {
    //     printf("data of stack a : %d\n", stack_a->index);
    //     stack_a = stack_a->next;
    // }
    // printf("---------------\n");
    // int x = 0;
    // while (stack_b)
    // {
    //     x++;
    //     printf("data of stack b : %d\n", stack_b->index);
    //     stack_b = stack_b->next;
    // }
}
