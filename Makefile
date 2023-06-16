# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 02:35:28 by rlevilla          #+#    #+#              #
#    Updated: 2023/06/17 00:22:11 by rlevilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRCS = srcs/
DIR_OBJS = objs/
SRCS = srcs/path.c \
	   srcs/main.c \

OBJS	= ${SRCS:.c=.o}

LIBFT = libft

CFLAGS	= gcc -Wall -Wextra -Werror

RM	= rm -f

OPTIONS	= -I

NAME	= pipex

all:	${NAME}

$(NAME): $(OBJS)
	$(MAKE) -C libft/
	$(CFLAGS) $(OBJS) -L./libft/ -lft -o $(NAME)

.c.o:
			${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
		${MAKE} -C /libft/

clean:
			${MAKE} -C libft/ clean
			${RM} ${OBJS}

fclean:	clean
				${RM} ${NAME}
				${MAKE} -C libft/ fclean
re:	fclean all

.PHONY: clean fclean all re
