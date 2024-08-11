/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:42:26 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:07:21 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

void index_position(t_push_swap_stack *stack) 
{
	size_t i;
	size_t midpoint;

	if (!stack)
		return;

	midpoint = get_stack_len(stack) / 2;
	i = 0;

	while (stack) 
	{
		stack->count = i;
		stack->push_midval = (i <= midpoint);//midval
		stack = stack->next;
		++i;
	}
}

// Function assign each node in stack 'a' a pointer to the closest smaller value node in stack 'b' 
void assign_t4a(t_push_swap_stack *a, t_push_swap_stack *b) //or the maximum value if no smaller exists.
{
    t_push_swap_stack *present_bnode;
    t_push_swap_stack *desired_node;
    long small_num_tracker;
    while (a)
    {
        small_num_tracker = LONG_MIN;
        desired_node = NULL;
        present_bnode = b;
        while (present_bnode)
        {
            if (present_bnode->data < a->data && present_bnode->data > small_num_tracker) // Find the largest value in 'b' that is smaller than the current value in 'a'
            {
                small_num_tracker = present_bnode->data;
                desired_node = present_bnode;
            }
            present_bnode = present_bnode->next;
        }
        if (!desired_node)// If no valid smaller value is found in 'b', set desired_node to the max value in 'b'
        {
            a->desired_node = max_stackval(b);
        }
        else
            a->desired_node = desired_node;
        a = a->next;
    }
}

void	push_cost4a(t_push_swap_stack *a, t_push_swap_stack *b)
{
	int	a_size;
	int	b_size;
	
	a_size = get_stack_len(a);
	b_size = get_stack_len(b);
	while (a)
	{
		a->nearval_cal = a->count;  // Initialize the rotation count with current node's count in 'a'
		if (!(a->push_midval))  // If push_midval is not set, calculate it
		{
			a->push_midval = a_size - (a->count);  // Calculate rotations needed to bring this node to the top of 'a'
		}
		if (a->desired_node->push_midval)  // If corresponding node in 'b' has a rotation value
		{
			a->nearval_cal += a->desired_node->count;  // Add the rotation count from 'b'
		}
		else  // If midpoint is not set for the desired node in 'b'
		{
			a->nearval_cal += b_size - (a->desired_node->count);  // Calculate rotations from the bottom of 'b'
		}
		a = a->next;
	}
}
//Function used the data obtained from the push_cost4a function to look for the smallest value
void chose_closest_val(t_push_swap_stack *stack)
{
	long closest_val;
	t_push_swap_stack *closest_node;

	if (!stack)
		return;

	closest_val = LONG_MAX;
	closest_node = NULL;

	while (stack)
	{
		if (stack->nearval_cal < closest_val)// Check if the current node has a smaller nearval_cal value
		{
			closest_val = stack->nearval_cal; // Update closest_val
			closest_node = stack; // Update the pointer to the closest node
		}
		stack = stack->next; // Move to the next node in the list
	}

	if (closest_node)
		closest_node->nearval = true; // Mark the closest node
}
// Function assign each node in stack 'b' a pointer to the closest smaller value node in stack 'a' 
void assign_t4b(t_push_swap_stack *a, t_push_swap_stack *b)
{
    t_push_swap_stack *present_anode;
    t_push_swap_stack *desired_node;
    long				big_num_tracker;
	
    while (b)
    {
        big_num_tracker = LONG_MAX;
        desired_node = NULL;
        present_anode = a;
        while (present_anode)
        {
            if (present_anode->data > b->data && present_anode->data < big_num_tracker) // Find the largest value in 'a' that is still smaller than the current value in 'b'
            {
                big_num_tracker = present_anode->data;
                desired_node = present_anode;
            }
            present_anode = present_anode->next;
        }
        if (!desired_node)// If no smaller value is found in 'a', assign the minimum value from 'a' to b->desired_node//possible
        {
            b->desired_node = min_stackval(a);
        }
        else
            b->desired_node = desired_node;
        b = b->next;
    }
}
