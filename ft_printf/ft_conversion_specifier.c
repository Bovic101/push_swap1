/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:01:43 by vodebunm          #+#    #+#             */
/*   Updated: 2024/02/18 07:07:54 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_specifier(const char c, va_list list, int *i)
{
	if (c == 'c')
		return (ft_characater_printf(va_arg(list, int)));
	if (c == 's')
		return (ft_str_printf(list));
	if (c == 'i' || c == 'd')
		return (ft_int_dec_number_print(va_arg(list, int)));
	if (c == 'p')
		return (ft_pointer(list));
	if (c == 'u')
		return (ft_int_dec_number_print(va_arg(list, unsigned int)));
	if (c == 'x')
		return (ft_pointer_printf(va_arg(list, unsigned int), c));
	if (c == 'X')
		return (ft_pointer_printf(va_arg(list, unsigned int), c));
	if (c == '%')
		return (ft_characater_printf(c));
	if (c == '\0')
		return (0);
	if (i != NULL)
		*i = *i - 1;
	return (0);
}
