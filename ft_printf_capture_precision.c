/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_capture_precision.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 23:58:01 by mmorel            #+#    #+#             */
/*   Updated: 2017/09/14 23:58:03 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_capture_precision(const char *restrict format,
	t_mods *mod, int index)
{
	int		count;
	char	*precision_number;
	char	*tmp;

	if (!(precision_number = (char *)malloc(2)))
		return (-1);
	count = 0;
	if (format[++index] >= 48 && format[index] <= 57)
	{
		precision_number[count++] = format[index++];
		precision_number[count] = '\0';
		while (format[index] >= 48 && format[index] <= 57)
		{
			if (!(tmp = (char *)malloc(ft_strlen(precision_number) + 2)))
				return (-1);
			ft_strcpy(tmp, precision_number);
			tmp[count++] = format[index++];
			tmp[count] = '\0';
			free(precision_number);
			precision_number = tmp;
		}
		mod->precision = ft_atoi(precision_number);
		return (count + 1);
	}
	return (1);
}
