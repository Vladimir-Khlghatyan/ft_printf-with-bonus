/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn1_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:02:40 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/22 18:02:44 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	i = ft_strlen(str);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

int	ft_unintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

int	pb(char c, int n)
{
	int	rv;

	rv = n;
	while (--n >= 0)
		write(1, &c, 1);
	return (rv);
}

int	ft_putsrt_free(char *str)
{
	int	rv;

	if (str == NULL)
		return (write(1, "\0", 1));
	rv = write(1, str, ft_strlen(str));
	if (str)
		free(str);
	return (rv);
}
