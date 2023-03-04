# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:09:12 by asacchin          #+#    #+#              #
#    Updated: 2023/03/04 16:11:10 by asacchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c Map/map.c Utils_function/utils.c Utils_function/utils2.c Movimento/update_map.c gnl/get_next_line.c gnl/get_next_line_utils.c Map/print_map.c Movimento/hooks.c

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