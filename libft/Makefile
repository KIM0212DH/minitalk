# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:09:13 by dokim2            #+#    #+#              #
#    Updated: 2022/03/31 18:25:42 by dokim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECT	= $(SRC:.c=.o)
OBJECT_B = $(SRC_B:.c=.o)
INCS	= libft.h
NAME = libft.a
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
bonus :
	make DO_BONUS=1
all : $(NAME)
clean :
	rm -f $(OBJECT) $(OBJECT_B)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re bonus