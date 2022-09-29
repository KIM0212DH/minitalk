# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:09:13 by dokim2            #+#    #+#              #
#    Updated: 2022/08/14 22:22:52 by dokim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= ft_printf.c check_type.c type_op.c write_sum.c
OBJECT	= $(SRC:.c=.o)
INCS	= ft_printf.h
NAME = libftprintf.a
DO_BONUS = 0
ifeq ($(DO_BONUS), 1)
	OBJECTS = $(OBJECT) $(OBJECT_B)
else
	OBJECTS = $(OBJECT)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)
$(NAME) : $(OBJECTS) $(INCS)
	ar rc $(NAME) $(OBJECTS)
all : $(NAME)
clean :
	rm -f $(OBJECT) $(OBJECT_B)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re