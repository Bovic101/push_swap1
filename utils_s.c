/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:24:43 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:08:29 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap_src/push_swap.h"

void *max_stackval(t_push_swap_stack *stack)
{
    long biggest_val;
    t_push_swap_stack *bigptr = NULL;
    
    if (!stack)
    {
        return (NULL);
    }
    
    biggest_val = LONG_MIN;// Initialize to the smallest possible long value
    while (stack)
    {
        if (stack->data > biggest_val)
        {
            biggest_val = stack->data;   // Update largest value
            bigptr = stack;                // Update pointer to current largest node
        }
        stack = stack->next;               // Move to the next node in the stack
    }
    
    return (bigptr);                       // Return the node with the largest value
}
void *max_stackval(t_push_swap_stack *stack)
{
    long smallest_val;
    t_push_swap_stack *smallptr = NULL;
    
    if (!stack)
    {
        return (NULL);
    }
    
    smallest_val = LONG_MAX;                // Initialize to the higest possible long value
    while (stack)
    {
        if (stack->data < smallest_val)
        {
            smallest_val = stack->data;     // Update largest value
            smallptr = stack;                // Update pointer to current largest node
        }
        stack = stack->next;               // Move to the next node in the stack
    }
    
    return (smallest_val);                       // Return the node with the largest value
}
// Function to calculate the length of a linked list (stack) in a push_swap program
int get_stack_len(t_push_swap_stack *stack)
{
    int i;

    if (!stack)
    {
        return (0);
    }
    i = 0;
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}