/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_to_str1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:17 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:24 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*c_to_str(int c)
{
	char	*str;

	if (c == 0)
		return (NULL);
	str = (char *)malloc(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*str_to_str(char *str, t_pf *pf)
{
	char	*s;
	int		i;

	if (!str)
		return (if_null_str(pf->ifdot, pf->dot));
	if (pf->ifdot == 0 || (pf->dot >= ft_strlen(str)))
		return (ft_strdup(str));
	s = malloc(pf->dot + 1);
	i = -1;
	while (++i < pf->dot)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

char	*p_to_str(size_t n)
{
	char	*str;
	size_t	tmp[100];
	int		i;
	int		j;

	if (n == 0)
		return (ft_strdup("0x0"));
	i = 0;
	while (n != 0)
	{
		tmp[i] = n % 16;
		n = n / 16;
		i++;
	}
	str = malloc(2 + i + 1);
	j = 0;
	str[j++] = '0';
	str[j++] = 'x';
	while (--i >= 0)
		str[j++] = "0123456789abcdef"[tmp[i]];
	str[j] = '\0';
	return (str);
}

char	*di_to_str(int n, t_pf *pf)
{
	int		rem;
	int		len;
	char	*str;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		rem = n % 10;
		n = n / 10;
		if (rem < 0)
			rem = -rem;
		str[len] = rem + '0';
	}
	if (sign == -1)
		str[0] = '-';
	str = check_dot_and_zero(str, pf);
	return (str);
}

char	*u_to_str(unsigned int n, t_pf *pf)
{
	int		len;
	char	*str;

	len = ft_unintlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	str = check_dot(str, pf);
	return (str);
}
