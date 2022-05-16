# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcesar-d <mcesar-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:00:15 by mcesar-d          #+#    #+#              #
#    Updated: 2022/05/16 03:08:22 by mcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	libftprintf.a
CFLAGS	=	-Wall -Wextra -Werror -O2
LIBFT	=	libft
DIR_S	=	src
DIR_O	=	obj
HEADER	=	include
SOURCES	=	ft_printf.c ft_printf_utils.c
SRCS	=	$(addprefix $(DIR_S)/,$(SOURCES))
OBJS	=	$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:	$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/ft_printf.h
				@mkdir -p obj
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

test:			$(NAME)
				@make -C Test

norm:
				norminette ./libft/
				@echo
				norminette ./$(HEADER)/
				@echo
				norminette ./$(DIR_S)/

clean:
				@rm -f $(OBJS)
				@rm -rf $(DIR_O)
				@make clean -C $(LIBFT)

fclean:			clean
				@rm -f $(NAME)
				@make fclean -C $(LIBFT)
				@make fclean -C Test

re:				fclean all

.PHONY:			fclean re norm all clean