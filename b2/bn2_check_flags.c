/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn2_check_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:01:55 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:10 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_hsign_plus_space(const char **str, t_pf *pf)
{
	initiator(pf);
	if (**str == '#')
	{
		while (**str == '#')
			(*str)++;
		while (**str >= '0' && **str <= '9')
			pf->hsign = get_number(str, pf->hsign);
	}
	if (**str == ' ')
	{
		pf->ifspace = 1;
		while (**str == ' ')
			(*str)++;
		while (**str >= '0' && **str <= '9')
			pf->space = get_number(str, pf->space);
	}
	if (**str == '+')
	{
		pf->ifplus = 1;
		while (**str == '+')
			(*str)++;
		while (**str >= '0' && **str <= '9')
			pf->plus = get_number(str, pf->plus);
	}
}
