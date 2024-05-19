/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:28:31 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/19 06:18:35 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_check_error(char *argv, t_list *temp)
{
	char	*s1;
	char	*s2;
	int		len;

	s1 = argv;
	s2 = ft_itoa(obtain_value(temp));
	len = ft_strlen(argv);
	if (ft_strncmp(s1, s2, len) != 0)
	{
		free(s2);
		return (1);
	}
	free(s2);
	return (0);
}

int	ft_duplicate(t_list *lst, int n)
{
	while (lst)
	{
		if (obtain_value(lst) != n)
			lst = lst->next;
		else
		{
			return (1);
			break ;
		}
	}
	return (0);
}
