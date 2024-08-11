/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:38:40 by vodebunm          #+#    #+#             */
/*   Updated: 2024/08/11 02:07:41 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int main(int argc, char **argv)
{
    t_push_swap_stack *a;
    t_push_swap_stack *b;
    char **args = argv;  // Default to argv unless we split
    
    a = NULL;
    b = NULL;

    if (argc < 2 || (argc == 2 && !argv[1][0])) // Handle cases with no input or empty argument
        return (1);
    
    if (argc == 2) // If a single argument is provided, split it into multiple arguments
    {
        args = ft_split(argv[1], ' ');//done
        if (!args) // Handle memory allocation failure
            return (1);
    }

    // Initialize stack 'a' with the provided arguments
    stack_a_init(&a, args + 1);//done
    if (!a)  // Check if initialization failed by checking if 'a' is NULL
    {
        if (argc == 2)  // Free args only if it was split
            free(args);
        return (1);
    }

    // Perform sorting only if the stack is not already sorted
    if (!sorted_stack(a))//done
    {
        size_t stack_len = length_stack(a);//check

        if (stack_len == 2)
            sa(&a, false);//check
        else if (stack_len == 3)
            alt_sorter(&a);
        else
            turks_sorter(&a, &b);//check
    }

    // Free the stacks and args if it was allocated by ft_split
    free_mystack(&a); // Free stack 'a'//check
    free_mystack(&b); // Free stack 'b'
    if (argc == 2)
        free(args);

    return (0);
}

