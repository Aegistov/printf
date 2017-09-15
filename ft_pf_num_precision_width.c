/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:27:33 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/09 19:27:34 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pf_num_width_pad(t_mods *mod, t_pf_string *nbr)
{
	int		flag_sign;
	int		width;
	int		hash;

	hash = mod->hash;
	flag_sign = 0;
	if ((mod->space || mod->plus) && !nbr->neg)
		flag_sign = 1;
	if (mod->width > (unsigned int)(nbr->len + flag_sign + hash))
	{
		width = (nbr->len == 1 && nbr->num_str[0] == '0' && mod->p_active) ?
			mod->width : mod->width - (nbr->len + flag_sign + hash);
		if (mod->zero && !nbr->ppad && mod->precision == 0)
			nbr->wpad = ft_strfill(nbr->wpad, '0', width);
		else
			nbr->wpad = ft_strfill(nbr->wpad, ' ', width);
		if (!(nbr->len == 1 && nbr->num_str[0] == '0' && mod->p_active))
			mod->width -= (nbr->len + flag_sign + hash);
	}
	else
		mod->width = 0;
}

void	ft_pf_num_precision_pad(t_mods *mod, t_pf_string *nbr)
{
	mod->precision -= ft_strlen(nbr->num_str);
	if (nbr->neg)
		mod->precision += 1;
	nbr->ppad = ft_strfill(nbr->ppad, '0', mod->precision);
}

int		ft_pf_num_precision_check(t_mods *mod, t_pf_string *nbr)
{
	int		len;

	len = 0;
	if ((int)mod->precision <= ft_strlen(nbr->num_str))
		len = ft_strlen(nbr->num_str);
	else
	{
		len = (nbr->neg) ? mod->precision + 1 : mod->precision;
		ft_pf_num_precision_pad(mod, nbr);
	}
	return (len);
}
