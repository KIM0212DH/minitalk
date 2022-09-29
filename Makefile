# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 20:50:03 by dokim2            #+#    #+#              #
#    Updated: 2022/09/26 20:57:55 by dokim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = MINITALK
SERVER = server
CLIENT = client

SERVER_NAME = server.a
CLIENT_NAME = client.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SERVER_FILE = server.c 
CLIENT_FILE = client.c

SERVER_BONUS_FILE = server_bonus.c
CLIENT_BONUS_FILE = client_bonus.c

INCS	= minitalk.h

DO_BONUS = 0
ifeq ($(DO_BONUS), 1)
	SERVER_OBJECT = $(SERVER_BONUS_FILE:.c=.o)
	CLIENT_OBJECT = $(CLIENT_BONUS_FILE:.c=.o)
else
	SERVER_OBJECT = $(SERVER_FILE:.c=.o)
	CLIENT_OBJECT = $(CLIENT_FILE:.c=.o)
endif

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT) $(INCS)

$(SERVER) : $(SERVER_OBJECT) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJECT) $(FT_PRINTF) $(LIBFT) -o $(SERVER)

$(CLIENT) :	$(CLIENT_OBJECT) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJECT) $(FT_PRINTF) $(LIBFT) -o $(CLIENT)


$(FT_PRINTF) : 
	make -C $(FT_PRINTF_DIR)

$(LIBFT) : 
	make -C $(LIBFT_DIR)
bonus :
	make DO_BONUS=1
	
clean :
	rm -f $(SERVER_OBJECT) $(CLIENT_OBJECT)
	rm -f $(SERVER_BONUS_FILE:.c=.o) $(CLIENT_BONUS_FILE:.c=.o)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re : fclean all