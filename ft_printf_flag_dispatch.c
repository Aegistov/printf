/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_dispatch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:27:37 by mmorel            #+#    #+#             */
/*   Updated: 2017/09/12 15:59:44 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_flag_dispatch(t_mods *mod, va_list insertion, int argument)
{
	int			(*argument_list[127])(va_list, t_mods *);
	int			len;
	static char *arg = "diuoxcspDXUSCOP%";

	len = 0;
	mod->arg = argument;
	argument_list['d'] = ft_printf_di;
	argument_list['D'] = ft_printf_di;
	argument_list['i'] = ft_printf_di;
	argument_list['o'] = ft_printf_o;
	argument_list['x'] = ft_printf_x;
	argument_list['X'] = ft_printf_x;
	argument_list['u'] = ft_printf_u;
	argument_list['U'] = ft_printf_u;
	argument_list['c'] = ft_printf_c;
	argument_list['C'] = ft_printf_c;
	argument_list['s'] = ft_printf_s;
	argument_list['S'] = ft_printf_s;
	argument_list['O'] = ft_printf_o;
	argument_list['p'] = ft_printf_p;
	argument_list['%'] = ft_printf_pct;
	len = (ft_strchr(arg, argument)) ?
	(*argument_list[argument])(insertion, mod) : write(1, &argument, 1);
	return (len);
}
