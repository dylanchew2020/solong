# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchew <lchew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 17:13:24 by lchew             #+#    #+#              #
#    Updated: 2022/05/14 22:01:24 by lchew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name:
NAME	=	so_long

# SOURCE CODE
SRC_DIR = ./
SRC	=	$(SRC_DIR)so_long.c
OBJ	=	$(SRC:%.c=%.o)

# HEADER
INC_DIR = ./
INC		=	$(INC_DIR)

# COMPILATION
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

# PRETTY
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "$(_SUCCESS) Window startup"

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:
	@ ./so_long

clean:
	@ $(RM) $(OBJ)
	@ printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ printf "$(_INFO) Window cache cleared.\n"

re: fclean all

.PHONY: all clean fclean re
