/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_zero11(char *str, int n)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 1;
	new_str = malloc(ismax(n, 11) + 2);
	new_str[i++] = '-';
	while (i <= (n - (len - 1)))
	{
		new_str[i] = '0';
		i++;
	}
	while (str[j])
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*fill_zero12(char *str, int n)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 1;
	new_str = malloc(ismax(n, 11) + 2);
	new_str[i++] = '-';
	while (i < (n - (len - 1)))
	{
		new_str[i] = '0';
		i++;
	}
	while (str[j])
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*fill_zero2(char *str, int n)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	new_str = malloc(ismax(n, 11) + 1);
	while (i < (n - len))
	{
		new_str[i] = '0';
		i++;
	}
	while (str[j])
	{
		new_str[i] = str[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*empty_str(char *str)
{
	char	*new_str;

	new_str = malloc(1);
	new_str[0] = '\0';
	free (str);
	return (new_str);
}

char	*check_dot_and_zero(char *str, t_pf *pf)
{
	int		len;

	if (pf->ifdot == 1 && pf->dot == 0 && str[0] == '0')
		return (empty_str(str));
	if (pf->ifdot == 0 && pf->zero == 0)
		return (str);
	len = ft_strlen(str);
	if (pf->ifdot == 1 && (pf->dot < len))
		return (str);
	if (pf->ifdot == 1)
	{
		if (str[0] == '-')
			return (fill_zero11(str, pf->dot));
		else
			return (fill_zero2(str, pf->dot));
	}
	else
	{
		if (str[0] == '-')
			return (fill_zero12(str, pf->zero));
		else
			return (fill_zero2(str, pf->zero));
	}
	return (NULL);
}
