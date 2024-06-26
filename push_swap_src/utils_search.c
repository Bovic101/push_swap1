/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:31:40 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 04:35:50 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

int	search_index_node(t_list *lst, int nbr)
{
	int	i;

	i = 0;
	while (obtain_value(lst) != nbr)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	search_position_b(t_list *b, int nbr)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (nbr > obtain_value(b) && nbr < obtain_value(ft_lstlast(b)))
		i = 0;
	else if (nbr > search_bigger_value(b) || nbr < search_smaller_value(b))
		i = search_index_node(b, search_bigger_value(b));
	else
	{
		temp = b->next;
		while (obtain_value(b) < nbr || obtain_value(temp) > nbr)
		{
			b = b->next;
			temp = b->next;
			i++;
		}
	}
	return (i);
}

int	search_bigger_value(t_list *lst)
{
	int	i;

	i = obtain_value(lst);
	while (lst != 0)
	{
		if (obtain_value(lst) > i)
			i = obtain_value(lst);
		lst = lst->next;
	}
	return (i);
}

int	search_smaller_value(t_list *lst)
{
	int	i;

	i = obtain_value(lst);
	while (lst != 0)
	{
		if (obtain_value(lst) < i)
			i = obtain_value(lst);
		lst = lst->next;
	}
	return (i);
}

int	search_position_a(t_list *a, int nbr)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (nbr < obtain_value(a) && nbr > obtain_value(ft_lstlast(a)))
		i = 0;
	else if (nbr > search_bigger_value(a) || nbr < search_smaller_value(a))
		i = search_index_node(a, search_smaller_value(a));
	else
	{
		temp = a->next;
		while (obtain_value(a) > nbr || obtain_value(temp) < nbr)
		{
			a = a->next;
			temp = a->next;
			i++;
		}
	}
	return (i);
}
