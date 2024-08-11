/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:13:23 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:08:05 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int rm_copy(t_push_swap_stack *a, int num)
{
    while (a)
    {
        if (a->data == num) // Check if current node's data matches number
        {
            return 1; 
        }
        a = a->next;
    }
    return(0);
}
void	free_mystack(t_push_swap_stack **stack)
{
	t_push_swap_stack	*cur;
	t_push_swap_stack	*temp;

	if (!stack || !*stack)  // Check if stack is valid
		return ;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		free(cur);          // Free the current node
		cur = temp;
	}
	*stack = NULL;  // Set the stack pointer to NULL after freeing
}
int format_check(const char *str) 
{
    if (str == NULL || *str == '\0') 
    {
        return (1);
    }
    if (!isdigit(*str) && (*str != '+' && *str != '-') || (str[1] == '\0' && (*str == '+' || *str == '-')))
    {
        return (1);
    }
    if (*str == '+' || *str == '-')
    {
        str++;
    }
    while (*str)
    {
        if (!isdigit(*str)) // Return an error if any character is not a digit
        {
            return (1);
        }
        str++;
    }
    return (0);
}
 void	 turk_implement_b(t_push_swap_stack *a, t_push_swap_stack *b)
 {
	index_position(a);
	index_position(b);
	assign_t4b(a,b);
 }

t_push_swap_stack *obtain_closest_v(t_push_swap_stack *stack)
{
    if (!stack)
    {
        return NULL;
    }
    while (stack)// Traverse the stack
    {
        // If nearval is true, return the current node
        if (stack->nearval)   // If near value is true, return the current node
        {
            return stack;
        }
        stack = stack->next;
    }
    return NULL;// If no node with nearval is found, return NULL
}
