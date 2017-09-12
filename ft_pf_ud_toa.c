/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ud_toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:59:10 by mmorel            #+#    #+#             */
/*   Updated: 2017/08/14 18:58:05 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_pf_llutoa_base(uintmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	str = NULL;
	size = ft_pf_llu_len_base(n, base);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	return (str);
}

char			*ft_pf_llutoa_base_up(uintmax_t n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789ABCDEF";

	str = NULL;
	size = ft_pf_llu_len_base(n, base);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	return (str);
}

char			*ft_pf_hhutoa_base(unsigned char n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789abcdef";

	str = NULL;
	size = ft_pf_hhu_len_base(n, base);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	return (str);
}

char			*ft_pf_hhutoa_base_up(unsigned char n, int base)
{
	char			*str;
	intmax_t		size;
	static char		*hex = "0123456789ABCDEF";

	str = NULL;
	size = ft_pf_hhu_len_base(n, base);
	if (n == 0)
		return ("0");
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		str[size--] = '\0';
		while (n >= (uintmax_t)base)
		{
			str[size] = hex[(n % base)];
			n /= base;
			size--;
		}
		str[size] = hex[(n % base)];
	}
	return (str);
}
