/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rot_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:22:12 by vodebunm          #+#    #+#             */
/*   Updated: 2024/07/26 01:50:49 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

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
void	activate_push(t_push_swap_stack **stack1, t_push_swap_stack **stack2)
{
	t_push_swap_stack	*pptr;

	if (!stack2 || !*stack2)
		return;
	pptr = *stack2;           // Store the top element of stack2
	*stack2 = (*stack2)->next; // Move the top element of stack2 to the next element
	if (*stack2)              // If stack2 is not empty after the pop
	{
		(*stack2)->prevnode = NULL; // Set the previous node of the new top element to NULL
	}
	pptr->prevnode = NULL;    // The popped element is now isolated from stack2

	if (!*stack1)             // If stack1 is empty
	{
		*stack1 = pptr;
		pptr->next = NULL;    // It becomes the only element in stack1
	}
	else                      // If stack1 is not empty
	{
		pptr->next = *stack1;  // Link the popped element to the top of stack1
		(*stack1)->prevnode = pptr; // Set the previous node of the old top to the new element
		*stack1 = pptr;        // Update the top of stack1 to the new element
	}
}
void pb(t_push_swap_stack **b, t_push_swap_stack **a, bool value)
{
    activate_push(b,a);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("Take the first element at the top of b and put it at the top of a\n");
    }
}
void pa(t_push_swap_stack **a, t_push_swap_stack **b, bool value)
{
    activate_push(a,b);
    if (!value)// If the 'value' flag is false, print the operation message
    {
        ft_printf("Take the first element at the top of a and put it at the top of b \n");
    }
}
void rot_func(t_push_swap_stack **stack)
{
    t_push_swap_stack *lstptr;
    t_push_swap_stack *first;

    if (!stack || !(*stack) || !(*stack)->next) // Check if stack is NULL or has only one element
    {
        return;
    }
    first = *stack; // Store the original first element
    lstptr = *stack;

    while (lstptr->next) // Traverse to the last element in the list
    {
        lstptr = lstptr->next;
    }
    lstptr->next = first; // Link last element to the first element
    first->prevnode = lstptr; // Set the original first element's prevnode to the last element
    *stack = first->next; // Move the head to the second element
    (*stack)->prevnode = NULL; // Unlink the new head from the previous head
    first->next = NULL; // Set the original first element's next to NULL
}
