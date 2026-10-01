/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 05:56:15 by vodebunm          #+#    #+#             */
/*   Updated: 2024/02/19 00:56:26 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		len;

	va_start(list, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[++i])
		{
			len += ft_conversion_specifier(s[i], list, &i);
			i++;
		}
		if (s[i] && s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			i++;
			len++;
		}
	}
	va_end(list);
	return (len);
}
