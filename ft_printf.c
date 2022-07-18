/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:13:00 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/29 21:14:27 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_mandatory(const char *str, va_list ap, int rv)
{
	if (*str == 'c')
		rv += ft_putchar(va_arg(ap, int));
	else if (*str == 's')
		rv += ft_putstr(va_arg(ap, char *));
	else if (*str == 'p')
		rv += ft_pnb_p(va_arg(ap, size_t), "0123456789abcdef");
	else if (*str == 'd' || *str == 'i')
		rv += ft_pn_di(va_arg(ap, int));
	else if (*str == 'u')
		rv += ft_pnb_ux(va_arg(ap, unsigned int), "0123456789");
	else if (*str == 'x')
		rv += ft_pnb_ux(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		rv += ft_pnb_ux(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		rv += write(1, "%", 1);
	return (rv);
}

static int	ft_bonus1(const char **str, va_list ap, int rv, t_pf *pf)
{
	ft_minus_zero_dot(str, pf);
	if (**str == 'c')
		rv += c_write1(va_arg(ap, int), pf);
	else if (**str == 's')
		rv += s_write1(va_arg(ap, char *), pf);
	else if (**str == 'p')
		rv += p_write1(va_arg(ap, size_t), pf);
	else if (**str == 'd' || **str == 'i')
		rv += di_write1(va_arg(ap, int), pf);
	else if (**str == 'u')
		rv += u_write1(va_arg(ap, unsigned int), pf);
	else if (**str == 'x')
		rv += x_write1(va_arg(ap, unsigned int), pf);
	else if (**str == 'X')
		rv += big_x_write1(va_arg(ap, unsigned int), pf);
	else if (**str == '%')
		rv += percent_write1(pf);
	return (rv);
}

static int	ft_bonus2(const char **str, va_list ap, int rv, t_pf *pf)
{
	ft_hsign_plus_space(str, pf);
	if (**str == 'x')
		rv += x_write2(va_arg(ap, unsigned int), pf);
	else if (**str == 'X')
		rv += big_x_write2(va_arg(ap, unsigned int), pf);
	else if (**str == 'd' || **str == 'i')
		rv += di_write2(va_arg(ap, int), pf);
	else if (**str == 's')
		rv += s_write2(va_arg(ap, char *), pf);
	else if (**str == '%')
		rv += percent_write2(pf);
	return (rv);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_pf	pf;
	int		rv;

	rv = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '-' || (*str >= '0' && *str <= '9') || *str == '.')
				rv = ft_bonus1(&str, ap, rv, &pf);
			else if (*str == '#' || *str == '+' || *str == ' ')
				rv = ft_bonus2(&str, ap, rv, &pf);
			else
				rv = ft_mandatory(str, ap, rv);
			str++;
			continue ;
		}
		rv += write(1, str++, 1);
	}
	va_end(ap);
	return (rv);
}
