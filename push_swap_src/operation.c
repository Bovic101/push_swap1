/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:31:12 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:07:30 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	a_b(t_push_swap_stack **a, t_push_swap_stack **b)
{
    t_push_swap_stack *closest_node;

    closest_node = obtain_closest_v(*a);// Obtain the node that is closest to the desired value or position

    if (closest_node == NULL || closest_node->desired_node == NULL)// Ensure the closest_node is valid before proceeding
        return;

    if (closest_node->push_midval && closest_node->desired_node->push_midval)// Determine the appropriate rotation based on the nodes' push_midval flag
    {
        rot_ab(a, b, closest_node); // rotate both stacks//check
    }
    else if (!closest_node->push_midval && !closest_node->desired_node->push_midval)
    {
        rrot_both(a, b, closest_node); // reverse rotate both stacks//check
    }
    push_activate(a, closest_node, 'a');// Activate  for pushing on both stacks//check
    push_activate(b, closest_node->desired_node, 'b');
    pb(b, a, false);// Execute the push from stack a to stack b//check
}
void b_a(t_push_swap_stack **a, t_push_swap_stack **b)
{
    if (!a || !b || !*b)// Ensure stacks 'a' and 'b' are valid before proceeding
        return;
    push_activate(a, (*b)->desired_node, 'a'); // Activate or prepare stack 'a' using the desired node of the top of stack 'b'
    pa(a, b, false);  // Push the top element from stack 'b' onto stack 'a'
}
void swap_func(t_push_swap_stack **stack)
{
    t_push_swap_stack *first;
    t_push_swap_stack *second;

    if (!*stack || !(*stack)->next)  // Check if the stack is empty or has only one element
    {
        return;
    }
    first = *stack;           // The first node in the stack
    second = (*stack)->next;  // The second node in the stack
    first->next = second->next;// Swap the two nodes
    if (second->next)
    {
        second->next->prevnode = first;
    }
    second->prevnode = first->prevnode;
    second->next = first;
    first->prevnode = second;
    *stack = second;// Update the stack pointer to point to the new first node
}
