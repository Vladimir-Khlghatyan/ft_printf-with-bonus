/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn2_write_formats1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	function4(t_pf *pf, char *str, int len, int rv)
{
	int	i;

	if (str[0] == '-')
	{
		i = -1;
		while (++i < (pf->plus - len))
			rv += write(1, " ", 1);
		rv += ft_putsrt_free(str);
	}
	else
	{
		i = -1;
		while (++i < (pf->plus - len - 1))
			rv += write(1, " ", 1);
		rv += write(1, "+", 1);
		rv += ft_putsrt_free(str);
	}
	return (rv);
}

int	function5(t_pf *pf, char *str, int len, int rv)
{
	int	i;

	i = -1;
	if (str[0] == '-')
	{
		while (++i < (pf->plus - len))
			rv += write(1, " ", 1);
		rv += ft_putsrt_free(str);
	}
	else
	{
		if (pf->space > len)
		{
			while (++i < (pf->plus - len))
				rv += write(1, " ", 1);
			rv += ft_putsrt_free(str);
		}
		else
		{
			rv += write(1, " ", 1);
			rv += ft_putsrt_free(str);
		}
	}	
	return (rv);
}

int	di_write2(int n, t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;

	str = di_to_str(n, pf);
	len = ft_strlen(str);
	rv = 0;
	if (pf->ifplus == 1)
		rv += function4(pf, str, len, rv);
	else if (pf->ifspace == 1)
		rv += function5(pf, str, len, rv);
	return (rv);
}

int	s_write2(char *s, t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;
	int		i;

	str = str_to_str(s, pf);
	len = ft_strlen(str);
	rv = 0;
	i = -1;
	while (++i < (pf->space - len))
		rv += write(1, " ", 1);
	rv += ft_putsrt_free(str);
	return (rv);
}
