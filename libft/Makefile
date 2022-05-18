# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:00:15 by mcesar-d          #+#    #+#              #
#    Updated: 2022/05/18 04:13:49 by mcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_strlen.c ft_nbrlen.c ft_strchr.c ft_itoa.c ft_utoa.c \
					ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c
OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

%.o:		%.c	./libft.h
			@$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re