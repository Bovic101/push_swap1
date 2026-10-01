/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_digit_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:46:41 by vodebunm          #+#    #+#             */
/*   Updated: 2024/02/16 23:00:22 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//calculate the number of digits when represented in a given base (num)
int	ft_calculate_digit_base(size_t n, int num)
{
	int	counter;

	if (n == 0)
	{
		return (1);
	}
	counter = 0;
	while (n > 0)
	{
		n = n / num;
		counter++;
	}
	return (counter);
}
