/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_write_formats2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	x_write1(unsigned int n, t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;

	if (pf->ifdot == 1 && pf->zero != 0)
	{
		pf->numb = pf->zero;
		pf->zero = 0;
	}
	str = x_to_str(n, pf);
	len = ft_strlen(str);
	rv = 0;
	if (ifmax(len, pf->minus, pf->numb, ismax(pf->zero, pf->dot)) == 1)
		rv += ft_putsrt_free(str);
	else if (ifmax(ismax(pf->zero, pf->dot), len, pf->minus, pf->numb) == 1)
		rv += function1(pf, str, len);
	else if (ifmax(pf->numb, ismax(pf->zero, pf->dot), len, pf->minus) == 1)
		rv += function2(pf, str, len);
	else if (ifmax(pf->minus, pf->numb, ismax(pf->zero, pf->dot), len) == 1)
		rv += function3(pf, str, len);
	return (rv);
}

int	big_x_write1(unsigned int n, t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;

	if (pf->ifdot == 1 && pf->zero != 0)
	{
		pf->numb = pf->zero;
		pf->zero = 0;
	}
	str = big_x_to_str(n, pf);
	len = ft_strlen(str);
	rv = 0;
	if (ifmax(len, pf->minus, pf->numb, ismax(pf->zero, pf->dot)) == 1)
		rv += ft_putsrt_free(str);
	else if (ifmax(ismax(pf->zero, pf->dot), len, pf->minus, pf->numb) == 1)
		rv += function1(pf, str, len);
	else if (ifmax(pf->numb, ismax(pf->zero, pf->dot), len, pf->minus) == 1)
		rv += function2(pf, str, len);
	else if (ifmax(pf->minus, pf->numb, ismax(pf->zero, pf->dot), len) == 1)
		rv += function3(pf, str, len);
	return (rv);
}

int	percent_write1(t_pf *pf)
{
	char	*str;
	int		len;
	int		rv;

	str = malloc(2);
	str[0] = '%';
	str[1] = '\0';
	len = ft_strlen(str);
	rv = 0;
	if (ifmax(len, pf->minus, pf->numb, ismax(pf->zero, pf->dot)) == 1)
		rv += ft_putsrt_free(str);
	else if (ifmax(ismax(pf->zero, pf->dot), len, pf->minus, pf->numb) == 1)
		rv += function1_for_str(pf, str, len);
	else if (ifmax(pf->numb, ismax(pf->zero, pf->dot), len, pf->minus) == 1)
		rv += function2(pf, str, len);
	else if (ifmax(pf->minus, pf->numb, ismax(pf->zero, pf->dot), len) == 1)
		rv += function3(pf, str, len);
	return (rv);
}
