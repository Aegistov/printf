/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capture_length.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:30:30 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/25 22:30:31 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	map_length(const char *restrict format, int index, t_mods *mod)
{
	if (format[index] == 'h')
		mod->length = h;
	else if (format[index] == 'l')
		mod->length = l;
	else if (format[index] == 'L')
		mod->length = L;
	else if (format[index] == 'z')
		mod->length = z;
	else if (format[index] == 'j')
		mod->length = j;
	else if (format[index] == 't')
		mod->length = t;
}

int		ft_printf_capture_length(const char *restrict format,
	t_mods *mod, int index)
{
	int		count;

	count = 0;
	if (format[index] == 'h' || format[index] == 'l' || format[index] == 'L' ||
		format[index] == 'z' || format[index] == 'j' || format[index] == 't')
	{
		if (format[index + 1] == 'h')
		{
			mod->length = hh;
			index++;
			count++;
		}
		else if (format[index + 1] == 'l')
		{
			mod->length = ll;
			index++;
			count++;
		}
		else
			map_length(format, index, mod);
		index++;
		count++;
	}
	return (count);
}
