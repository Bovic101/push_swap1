/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:06:52 by vodebunm          #+#    #+#             */
/*   Updated: 2024/05/21 01:07:00 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_src/push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			last_node = lst;
		lst = lst->next;
	}
	return (last_node);
}
