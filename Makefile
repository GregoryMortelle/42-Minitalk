# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 17:55:52 by grmortel          #+#    #+#              #
#    Updated: 2023/06/19 22:46:46 by grmortel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	= client
SERVER	=	server
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

SRC_C	=	client.c
SRC_S	=	server.c
OBJ_C	=	$(SRC_C:.c=.o)
OBJ_S	=	$(SRC_S:.c=.o)
INC		=	-I. -I$(LIBFT_DIR) -I$(LIBFT_DIR) \
			-I$(LIBFT_DIR)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_S) $(LIBFT)
	@ $(CC) $(CFLAG) $(OBJ_S) $(LIBFT) $(INC) -o $(SERVER)

$(CLIENT): $(OBJ_C) $(LIBFT)
	@ $(CC) $(CFLAG) $(OBJ_C) $(LIBFT) $(INC) -o $(CLIENT)

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(OBJ_C) $(OBJ_S)

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER) $(OBJ_C) $(OBJ_S)

re: fclean all

.PHONY: all clean fclean
