/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:36:42 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/11 11:36:43 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		arg_filter(const char *restrict format,
	int *index, int *len, va_list arguments)
{
	if (format[(*index)] == '%')
	{
		if (format[(*index) + 1] == '%')
		{
			ft_putchar_fd(format[(*index) + 1], 1);
			(*index) += 2;
		}
		else if (format[(*index) + 1] != '\0')
		{
			(*len) += ft_printf_parse(format, arguments, &(*index));
			(*index)++;
		}
		else
			return (0);
	}
	else
	{
		ft_putchar_fd(format[(*index)], 1);
		(*len)++;
		(*index)++;
	}
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		arguments;
	int			index;
	int			len;

	len = 0;
	index = 0;
	va_start(arguments, format);
	while (format[index] != '\0')
	{
		if (!arg_filter(format, &index, &len, arguments))
			return (0);
	}
	return (len);
}
