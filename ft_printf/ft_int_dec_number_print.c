/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec_number_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:19:29 by vodebunm          #+#    #+#             */
/*   Updated: 2024/02/16 23:33:03 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnum(size_t n)
{
	if (n > 9)
	{
		ft_putnum(n / 10);
		ft_putnum(n % 10);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, 1);
	}
}

int	ft_int_dec_number_print(long long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	ft_putnum(n);
	count += ft_calculate_digit_base(n, 10);
	return (count);
}
