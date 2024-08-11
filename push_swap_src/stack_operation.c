/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:30:42 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:48:46 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void stack_a_init(t_push_swap_stack **a, char **argv)
{
    int     i;
    long    value;

    i = 0;
    while (argv[i])
    {
        value = ft_atol(argv[i]);

        // Check for format errors, out-of-bounds values, and duplicates
        if (format_check(argv[i]) ||
            value > INT_MAX || value < INT_MIN ||
            rm_copy(*a, (int)value))
        {
            free_memory(a);  // Free the stack if any check fails
            *a = NULL;       // Set the stack pointer to NULL to indicate failure
            return;
        }

        join_lstnode(a, (int)value);  // Add the value to the stack
        i++;
    }
}

bool sorted_stack(t_push_swap_stack *stack)
{
    if (!stack)
    {
        return true;
    }
    while (stack->next)
    {
        if (stack->data > stack->next->data)
        {
            return false;
        }
        stack = stack->next; 
    }
    return true;
}
void alt_sorter(t_push_swap_stack **a)
{
    t_push_swap_stack *maxval;//pointer to the highest node
    
    maxval = max_stackval(*a); //function returns a pointer to the node with the max value.//check
    
    if (maxval == *a)
    {
        ra(a, false); // Rotate if the max value is at the top of the stack
    }
    else if ((*a)->next == maxval)
    {
        rra(a, false); // Reverse rotate if the max value is next in the stack
    }
    
    if ((*a)->data > (*a)->next->data)
    {
        sa(a, false); // Swap the first two elements if the first one is larger than the second
    }
}
void turks_sorter(t_push_swap_stack **a, t_push_swap_stack **b)
{
    int a_length;

    a_length = get_stack_len(*a);

    if (a_length-- > 3 && !sorted_stack(*a))
        pb(b, a, false);

    if (a_length-- > 3 && !sorted_stack(*a))
        pb(b, a, false);

    while (a_length-- > 3 && !sorted_stack(*a))
    {
        turk_implement(*a, *b);
        a_b(a, b);
    }

    alt_sorter(a);
    while (*b)
    {
        turk_implement_b(*a, *b);
        b_a(a, b);
    }
    index_position(*a);
    data_value(a);
}

void data_value(t_push_swap_stack **a)//check smallest value athe top
{
    t_push_swap_stack *min_val;

    min_val = min_stackval(*a);
    while ((*a)->data != min_val->data) // Rotate until the minimum value is at the top of the stack
    {
        if (min_val->push_midval)
        {
            ra(a, false);
        }
        else
        {
            rra(a, false);
        }
    }
}