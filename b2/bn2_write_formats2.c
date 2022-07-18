/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn2_write_formats2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	x_write2(unsigned int n, t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;
	int		i;

	str = x_to_str(n, pf);
	len = ft_strlen(str);
	rv = 0;
	i = -1;
	if (str[0] == '0')
	{
		while (++i < (pf->hsign - len))
			rv += write(1, " ", 1);
		rv += ft_putsrt_free(str);
	}
	else
	{
		while (++i < (pf->hsign - 2 - len))
			rv += write(1, " ", 1);
		rv += write(1, "0x", 2);
		rv += ft_putsrt_free(str);
	}
	return (rv);
}

int	big_x_write2(unsigned int n, t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;
	int		i;

	str = big_x_to_str(n, pf);
	len = ft_strlen(str);
	rv = 0;
	i = -1;
	if (str[0] == '0')
	{
		while (++i < (pf->hsign - len))
			rv += write(1, " ", 1);
		rv += ft_putsrt_free(str);
	}
	else
	{
		while (++i < (pf->hsign - 2 - len))
			rv += write(1, " ", 1);
		rv += write(1, "0X", 2);
		rv += ft_putsrt_free(str);
	}
	return (rv);
}

int	percent_write2(t_pf *pf)
{
	int		rv;
	int		sp;
	int		i;

	rv = 0;
	sp = 0;
	i = -1;
	if ((pf->hsign >= pf->space) && (pf->hsign >= pf->plus))
		sp = pf->hsign;
	else if ((pf->space >= pf->hsign) && (pf->space >= pf->plus))
		sp = pf->space;
	else
		sp = pf->plus;
	while (++i < (sp - 1))
			rv += write(1, " ", 1);
	rv += write(1, "%", 1);
	return (rv);
}
