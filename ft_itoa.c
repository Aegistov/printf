/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:53:33 by mmorel            #+#    #+#             */
/*   Updated: 2016/11/08 16:12:44 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_itoa_base(intmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	str = NULL;
	size = ft_intlen_base(n, base);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		if (n < 0)
			str[0] = '-';
		str[size--] = '\0';
		while (n >= base || n < -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	return (str);
}

char			*ft_itoa_base_up(intmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789ABCDEF";

	str = NULL;
	size = ft_intlen_base(n, base);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		if (n < 0)
			str[0] = '-';
		str[size--] = '\0';
		while (n >= base || n < -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	return (str);
}
