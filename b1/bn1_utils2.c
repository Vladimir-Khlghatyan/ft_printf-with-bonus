/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	function1(t_pf *pf, char *str, int len)
{
	int	rv;

	rv = 0;
	if (str[0] == '\0')
		rv += pb(' ', ismax(pf->zero, pf->dot) - len);
	else
		rv += pb('0', ismax(pf->zero, pf->dot) - len);
	rv += ft_putsrt_free(str);
	return (rv);
}

int	function1_for_str(t_pf *pf, char *str, int len)
{
	int	rv;

	rv = 0;
	if (pf->ifdot == 0)
		rv += pb('0', ismax(pf->zero, pf->dot) - len);
	rv += ft_putsrt_free(str);
	if (pf->minus > ft_strlen(str))
		rv += pb(' ', pf->minus - ft_strlen(str));
	return (rv);
}

int	function2(t_pf *pf, char *str, int len)
{
	int	rv;

	rv = 0;
	if (str == NULL)
		rv += pb(' ', pf->numb - ismax(len, ismax(pf->zero, pf->dot)) - 1);
	else
		rv += pb(' ', pf->numb - ismax(len, ismax(pf->zero, pf->dot)) - 0);
	rv += pb('0', my_abs(ismax(pf->zero, pf->dot), len));
	rv += ft_putsrt_free(str);
	return (rv);
}

int	function3(t_pf *pf, char *str, int len)
{
	int	rv;

	rv = 0;
	rv += ft_putsrt_free(str);
	rv += pb('0', my_abs(ismax(pf->zero, pf->dot), len));
	if (str == NULL)
		rv += pb(' ', pf->minus - ismax(len, ismax(pf->zero, pf->dot)) - 1);
	else
		rv += pb(' ', pf->minus - ismax(len, ismax(pf->zero, pf->dot)) - 0);
	return (rv);
}

char	*if_null_str(int ifdot, int dot)
{
	if (ifdot == 1 && dot == 0)
		return (ft_strdup(""));
	if (ifdot == 1 && dot == 1)
		return (ft_strdup("("));
	if (ifdot == 1 && dot == 2)
		return (ft_strdup("(n"));
	if (ifdot == 1 && dot == 3)
		return (ft_strdup("(nu"));
	if (ifdot == 1 && dot == 4)
		return (ft_strdup("(nul"));
	if (ifdot == 1 && dot == 5)
		return (ft_strdup("(null"));
	if (ifdot == 1 && dot >= 6)
		return (ft_strdup("(null)"));
	return (ft_strdup("(null)"));
}
