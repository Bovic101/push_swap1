/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:38:40 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 05:04:43 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	obtain_value(t_list *elem)
{
	return (*((int *)(elem->content)));
}

t_list	*string_covert_int(char *content)
{
	int	*tmp;

	tmp = malloc(sizeof(int));
	*tmp = ft_atoi(content);
	return (ft_lstnew(tmp));
}

void	print_list(t_list *a)
{
	t_list	*temp_a;

	temp_a = a;
	while (temp_a != 0)
	{
		ft_printf("%d\n", obtain_value(temp_a));
		temp_a = temp_a->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*temp;
	int		i;

	a = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		ft_error();
	i = 1;
	while (i < argc)
	{
		temp = string_covert_int(argv[i]);
		if (ft_check_error(argv[i], temp) || ft_duplicate(a, ft_atoi(argv[i])))
		{
			ft_lstclear(&temp, free);
			ft_lstclear(&a, free);
			ft_error();
		}
		ft_lstadd_back(&a, temp);
		i++;
	}
	if (sorted_checker(a) == 0)
		sort_linklist(&a);
	ft_lstclear(&a, free);
	return (0);
}
