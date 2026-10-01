/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 06:30:03 by vodebunm          #+#    #+#             */
/*   Updated: 2024/02/18 06:53:38 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(va_list list)
{
	void		*p;
	long int	a;
	int			b;

	b = 0;
	p = va_arg(list, void *);
	if (p == NULL)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	else
	{
		a = (unsigned long int)p;
		ft_putstr_fd("0x", 1);
		b = ft_pointer_printf(a, 'x');
	}
	return (b + 2);
}
