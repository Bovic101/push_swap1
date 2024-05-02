/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:55:37 by vodebunm          #+#    #+#             */
/*   Updated: 2023/11/03 15:21:17 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function that counts the no. of node in the linked list

int	ft_lstsize(t_list *lst)
{
	int	len_num;

	len_num = 0;
	while (lst)
	{
		lst = lst->next;
		len_num++;
	}
	return (len_num);
}
