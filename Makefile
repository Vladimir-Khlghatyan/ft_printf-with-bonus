# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:12:13 by vkhlghat          #+#    #+#              #
#    Updated: 2022/03/29 14:41:36 by vkhlghat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		./utils/ft_pn_di.c \
			./utils/ft_pnb_p.c \
			./utils/ft_pnb_ux.c \
			./utils/ft_putchar.c \
			./utils/ft_putstr.c \
			./utils/ft_strlen.c \
			./b1/bn1_chech_flags.c \
			./b1/bn1_to_str1.c \
			./b1/bn1_to_str2.c \
			./b1/bn1_utils1.c \
			./b1/bn1_utils2.c \
			./b1/bn1_utils3.c \
			./b1/bn1_utils4.c \
			./b1/bn1_write_formats1.c \
			./b1/bn1_write_formats2.c \
			./b2/bn2_check_flags.c \
			./b2/bn2_write_formats1.c \
			./b2/bn2_write_formats2.c \
			ft_printf.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -f
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:			
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

bonus:		fclean all

re:			fclean all

.PHONY:		all clean fclean bonus re
