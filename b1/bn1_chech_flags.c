/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_chech_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:01:55 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:10 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	initiator(t_pf *pf)
{
	pf->minus = 0;
	pf->numb = 0;
	pf->zero = 0;
	pf->dot = 0;
	pf->ifdot = 0;
	pf->hsign = 0;
	pf->plus = 0;
	pf->space = 0;
	pf->ifplus = 0;
	pf->ifspace = 0;
}	

int	get_number(const char **str, int num)
{
	num = num * 10 + (**str - 48);
	(*str)++;
	return (num);
}

void	ft_minus_zero_dot(const char **str, t_pf *pf)
{
	initiator(pf);
	if (**str == '-')
	{
		while (**str == '-')
			(*str)++;
		while (**str >= '0' && **str <= '9')
			pf->minus = get_number(str, pf->minus);
	}
	if (**str == '0')
	{
		while (**str == '0')
			(*str)++;
		while (**str >= '0' && **str <= '9')
			pf->zero = get_number(str, pf->zero);
	}
	while (**str >= '0' && **str <= '9')
		pf->numb = get_number(str, pf->numb);
	if (**str == '.')
	{
		pf->ifdot = 1;
		(*str)++;
		while (**str >= '0' && **str <= '9')
			pf->dot = get_number(str, pf->dot);
	}
}
