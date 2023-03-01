# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:09:12 by asacchin          #+#    #+#              #
#    Updated: 2023/03/01 20:12:35 by asacchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c Map/map.c utils.c utils2.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_itoa.c print_map.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CLFAGS = -Wall -Wextra -Werror

LINKAR =  -framework OpenGL -framework AppKit

RM = rm -f

NAME = so_long

GETNEXTLINE = gnl/get_next_line.a

PRINTF = ft_printf/libftprintf.a

LIBX = minilibx_opengl_20191021/libmlx.a

INCLUDE = -I include

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${LINKAR} ${INCLUDE} ${OBJS} ${PRINTF} ${LIBX} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all