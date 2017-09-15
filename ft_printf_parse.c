/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:37:47 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/10 15:37:50 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_parse(const char *restrict format,
	va_list arguments, int *start)
{
	t_mods	*mod;

	if (!(mod = (t_mods *)ft_memalloc(sizeof(t_mods))))
		return (-1);
	if (format[(*start)] == '%')
	{
		(*start)++;
		(*start) += ft_printf_capture_flags(format, mod, *start);
		(*start) += ft_printf_capture_width(format, mod, (*start));
		if (format[(*start)] == '.')
		{
			mod->p_active = 1;
			(*start) += ft_printf_capture_precision(format, mod, (*start));
		}
		(*start) += ft_printf_capture_length(format, mod, (*start));
	}
	return (ft_printf_flag_dispatch(mod, arguments, format[(*start)]));
}
