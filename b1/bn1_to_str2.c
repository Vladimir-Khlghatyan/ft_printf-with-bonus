/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_to_str2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:29 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:34 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*x_to_str(unsigned int n, t_pf *pf)
{
	char			*str;
	unsigned int	tmp[100];
	int				i;
	int				j;

	if (n == 0)
	{
		str = ft_strdup("0");
		str = check_dot(str, pf);
		return (str);
	}
	i = 0;
	while (n != 0)
	{
		tmp[i++] = n % 16;
		n = n / 16;
	}
	str = malloc(i + 1);
	j = 0;
	while (--i >= 0)
		str[j++] = "0123456789abcdef"[tmp[i]];
	str[j] = '\0';
	str = check_dot(str, pf);
	return (str);
}

char	*big_x_to_str(unsigned int n, t_pf *pf)
{
	char			*str;
	unsigned int	tmp[100];
	int				i;
	int				j;

	if (n == 0)
	{
		str = ft_strdup("0");
		str = check_dot(str, pf);
		return (str);
	}
	i = 0;
	while (n != 0)
	{
		tmp[i++] = n % 16;
		n = n / 16;
	}
	str = malloc(i + 1);
	j = 0;
	while (--i >= 0)
		str[j++] = "0123456789ABCDEF"[tmp[i]];
	str[j] = '\0';
	str = check_dot(str, pf);
	return (str);
}
