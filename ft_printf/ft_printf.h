/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 03:07:54 by vodebunm          #+#    #+#             */
/*   Updated: 2024/02/18 06:40:09 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_str_printf(va_list list);
int		ft_int_dec_number_print(long long int n);
int		ft_pointer_printf(size_t n, char c);
int		ft_characater_printf(char c);
int		ft_conversion_specifier(const char c, va_list list, int *i);
int		ft_calculate_digit_base(size_t n, int num);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_pointer(va_list list);

#endif