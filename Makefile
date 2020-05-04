# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: challeau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 18:08:08 by challeau          #+#    #+#              #
#    Updated: 2020/04/28 14:33:29 by challeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	= 	ft_printf.c \
		srcs/add_char_fcts.c \
		srcs/buff_fcts.c \
		srcs/char_conv_fcts.c \
		srcs/num_conv_fcts.c \
		srcs/flag_fcts.c \
		srcs/ft_bzero.c \
		srcs/ft_char_to_str.c \
		srcs/ft_dec_to_base.c \
		srcs/ft_intlen.c \
		srcs/ft_itoa.c \
		srcs/ft_memdel.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_realloc.c \
		srcs/ft_strcat.c \
		srcs/ft_strchr_index.c \
		srcs/ft_strcmp.c \
		srcs/ft_strdup.c \
		srcs/ft_strjoin.c \
		srcs/ft_strlcat.c \
		srcs/ft_strlcpy.c \
		srcs/ft_strlen.c \
		srcs/ft_strlowcase.c \
		srcs/ft_strrev.c \
		srcs/ft_utoa.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	inc/ft_printf.h

RM	=	rm -f

FLAGS	=	-Wall -Wextra -Werror -g

.c.o:
	clang ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	ar -rcs libftprintf.a ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re

