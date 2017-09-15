/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capture_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 00:23:47 by mmorel            #+#    #+#             */
/*   Updated: 2017/09/15 00:23:48 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_capture_flags(const char *restrict format, t_mods *mod, int index)
{
	int		count;

	count = 0;
	while (format[index] == '-' || format[index] == '0' ||
		format[index] == '+' || format[index] == '#' || format[index] == ' ')
	{
		if (format[index] == '-')
			mod->left_align = 1;
		if (format[index] == '0')
			mod->zero = 1;
		if (format[index] == '+')
			mod->plus = 1;
		if (format[index] == '#')
			mod->hash = 1;
		if (format[index] == ' ')
			mod->space = 1;
		index += 1;
		count++;
	}
	return (count);
}
