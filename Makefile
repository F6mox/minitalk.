# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fal-kaf <fal-kaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 10:49:36 by fatima            #+#    #+#              #
#    Updated: 2025/06/30 20:10:07 by fal-kaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT	= client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF) -o $(NAME_CLIENT)

bonus: $(FT_PRINTF) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(FT_PRINTF) -o $(NAME_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(FT_PRINTF) -o $(NAME_CLIENT_BONUS)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
