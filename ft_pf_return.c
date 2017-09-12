/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:43:38 by mmorel            #+#    #+#             */
/*   Updated: 2017/08/15 14:01:46 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pf_return(t_mods *mod, t_pf_string *arg, int count)
{
	if ((mod->precision > mod->width))
	{
		return (arg->len + mod->width + count);
	}
	else if (mod->p_active && (arg->len == 1 && arg->num_str[0] == '0'))
	{
		return (mod->width + count);
	}
	else
	{
		return (arg->len + mod->width + count);
	}
}
