/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:25:32 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:07:02 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void	turk_implement(t_push_swap_stack *a, t_push_swap_stack *b)
{
	index_position(a);
	index_position(b);
	assign_t4a(a,b);
	push_cost4a(a, b);
	chose_closest_val(a);//set a node to the lowest value
}
// Continue rotating both stacks simultaneously
void rrot_both(t_push_swap_stack **a, t_push_swap_stack **b, t_push_swap_stack *closest_node)
{
    
    while (*b != closest_node->desired_node && *a != closest_node)
    {
        rrr(a, b, false);//false send the operation message to the fd//done
    }
    index_position(*a);  // update the indices/positions of elements in stack
    index_position(*b);
}
void rr(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
    rot_func(a);//rotate a
    rot_func(b);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("rotation operation of ra and rb\n");
    }
}
void rev_rot_ab(t_push_swap_stack **stack)
{
    t_push_swap_stack *lastptr;
    t_push_swap_stack *second_lastptr;

    if (!*stack || !(*stack)->next)
    {
        return;
    }
    lastptr = *stack; // Search for the last node
    while (lastptr->next)
    {
        lastptr = lastptr->next;
    }
    second_lastptr = lastptr->prevnode;// Find the second last node
    second_lastptr->next = NULL;// detach lstnod
    lastptr->next = *stack; // Move last node to the front
    lastptr->prevnode = NULL;
    (*stack)->prevnode = lastptr;
    *stack = lastptr; // Update stack head
}
void free_memory(t_push_swap_stack **a)
{
    if (a != NULL)
    {
        free(*a);
        *a = NULL; // Set the pointer to NULL to avoid dangling pointers
    }
    fprintf(stderr, "Error\n");
    exit(EXIT_FAILURE);
}