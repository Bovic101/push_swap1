/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-odebunmi <victor-odebunmi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:38:40 by vodebunm          #+#    #+#             */
/*   Updated: 2026/10/01 18:26:31 by victor-odeb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap_stack	*a;
	t_push_swap_stack	*b;
	char				**args;
	bool				split;
	size_t				stack_len;

	a = NULL;
	b = NULL;
	args = NULL;
	split = false;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!argv[1][0])
			return (0);
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			free_split(args);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		split = true;
	}
	else
		args = argv + 1;
	stack_a_init(&a, args);
	if (!a)
	{
		if (split)
			free_split(args);
		return (1);
	}
	if (!sorted_stack(a))
	{
		stack_len = get_stack_len(a);
		if (stack_len == 2)
			sa(&a, false);
		else if (stack_len == 3)
			alt_sorter(&a);
		else
			turks_sorter(&a, &b);
	}
	free_mystack(&a);
	free_mystack(&b);
	if (split)
		free_split(args);
	return (0);
}


