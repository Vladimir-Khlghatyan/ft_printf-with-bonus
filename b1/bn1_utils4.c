/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*check_dot(char *str, t_pf *pf)
{
	char	*new_str;
	int		i;
	int		j;

	if (pf->ifdot == 1 && pf->dot == 0 && ft_strlen(str) == 1 && str[0] == '0')
	{
		new_str = ft_strdup("\0");
		free(str);
		return (new_str);
	}
	else if (pf->ifdot == 1 && (pf->dot > ft_strlen(str)))
	{
		new_str = malloc(pf->dot + 1);
		i = -1;
		while (++i < (pf->dot - ft_strlen(str)))
			new_str[i] = '0';
		j = -1;
		while (str[++j])
			new_str[i++] = str[j];
		new_str[i] = '\0';
		free(str);
		return (new_str);
	}
	return (str);
}

int	ifmax(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d)
		return (1);
	return (0);
}

int	ismax(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	my_abs(int a, int b)
{
	if (a < b)
		return (0);
	return (a - b);
}
