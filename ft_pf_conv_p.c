/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:14:34 by mmorel            #+#    #+#             */
/*   Updated: 2017/06/09 19:14:35 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_p(va_list insertion, t_mods *mod)
{
	t_pf_string	nbr;
	int			count;

	ft_pf_str_init(&nbr);
	nbr.arg.vdpt = va_arg(insertion, void *);
	mod->hash = 2;
	count = 0;
	nbr.num_str = ft_pf_ud_toa_dispatch(mod, nbr.arg.mint, 16);
	nbr.len = ft_pf_num_precision_check(mod, &nbr);
	ft_pf_num_width_pad(mod, &nbr);
	count = ft_pf_num_print_order(mod, &nbr);
	return (ft_pf_return(mod, &nbr, count));
}
