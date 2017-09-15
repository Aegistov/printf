/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_d_toa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:28:36 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/07 22:28:37 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_pf_lldtoa_base(intmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	str = NULL;
	size = ft_pf_lld_len_base(n, 10);
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

char			*ft_pf_hhdtoa_base(char n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	str = NULL;
	size = ft_pf_hhd_len_base(n, 10);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		if (n < 0)
			str[0] = '-';
		str[size--] = '\0';
		while (n >= base || n <= -base)
		{
			str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base) * (n < 0 ? -1 : 1)];
	}
	return (str);
}
