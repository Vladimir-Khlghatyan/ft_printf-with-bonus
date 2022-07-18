/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:14:47 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/29 18:08:05 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pf
{	
	int	minus;
	int	numb;
	int	zero;
	int	dot;
	int	ifdot;
	int	hsign;
	int	plus;
	int	ifplus;
	int	space;
	int	ifspace;

}				t_pf;

/* mandatory */
int		ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
int		ft_pnb_p(size_t n, char *base);
int		ft_pnb_ux(unsigned int n, char *base);
int		ft_pn_di(int n);
int		ft_printf(const char *str, ...);

/* bn1_bonus_part1.c */
void	initiator(t_pf *pf);
int		get_number(const char **str, int num);
void	ft_minus_zero_dot(const char **str, t_pf *pf);

/* bn1_to_str1.c */
char	*c_to_str(int c);
char	*str_to_str(char *str, t_pf *pf);
char	*p_to_str(size_t n);
char	*di_to_str(int n, t_pf *pf);
char	*u_to_str(unsigned int n, t_pf *pf);

/* bn1_to_str2.c */
char	*x_to_str(unsigned int n, t_pf *pf);
char	*big_x_to_str(unsigned int n, t_pf *pf);

/* bn1_utils1.c */
char	*ft_strdup(char *str);
int		ft_intlen(int n);
int		ft_unintlen(unsigned int n);
int		pb(char c, int n);
int		ft_putsrt_free(char *str);

/* bn1_utils2.c */
int		function1(t_pf *pf, char *str, int len);
int		function1_for_str(t_pf *pf, char *str, int len);
int		function2(t_pf *pf, char *str, int len);
int		function3(t_pf *pf, char *str, int len);
char	*if_null_str(int ifdot, int dot);

/* bn1_utils3.c */
char	*fill_zero11(char *str, int n);
char	*fill_zero12(char *str, int n);
char	*fill_zero2(char *str, int n);
char	*empty_str(char *str);
char	*check_dot_and_zero(char *str, t_pf *pf);

/* bn1_utils4.c */
char	*check_dot(char *str, t_pf *pf);
int		ifmax(int a, int b, int c, int d);
int		ismax(int a, int b);
int		my_abs(int a, int b);

/* bn1_write_formats1.c */
int		c_write1(char c, t_pf *pf);
int		s_write1(char *s, t_pf *pf);
int		p_write1(size_t n, t_pf *pf);
int		di_write1(int n, t_pf *pf);
int		u_write1(unsigned int n, t_pf *pf);

/* bn1_write_formats2.c */
int		x_write1(unsigned int n, t_pf *pf);
int		big_x_write1(unsigned int n, t_pf *pf);
int		percent_write1(t_pf *pf);

/* bn2_bonus_part2.c */
void	ft_hsign_plus_space(const char **str, t_pf *pf);

/* bn2_write_formats1.c */
int		function4(t_pf *pf, char *str, int len, int rv);
int		function5(t_pf *pf, char *str, int len, int rv);
int		di_write2(int n, t_pf *pf);
int		s_write2(char *s, t_pf *pf);

/* bn2_write_formats2.c */
int		x_write2(unsigned int n, t_pf *pf);
int		big_x_write2(unsigned int n, t_pf *pf);
int		percent_write2(t_pf *pf);

#endif
