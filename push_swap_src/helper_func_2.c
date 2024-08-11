/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:13:23 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:19:32 by vodebunm         ###   ########.fr       */
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
    // Check if the string is NULL or empty
    if (str == NULL || *str == '\0') 
    {
        return 1; // Return 1 for invalid input
    }

    // Check for a valid sign character and ensure it is not a standalone character
    if ((*str == '+' || *str == '-') && *(str + 1) == '\0') 
    {
        return 1; // Return 1 if a sign is followed by nothing
    }

    // Move past the sign if present
    if (*str == '+' || *str == '-') 
    {
        str++;
    }

    // Ensure the remaining characters are all digits
    while (*str) 
    {
        if (!isdigit((unsigned char)*str)) 
        {
            return 1; // Return 1 if any character is not a digit
        }
        str++;
    }

    return 0; // Return 0 for a valid input
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
