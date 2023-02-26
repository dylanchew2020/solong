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
SRC	=	so_long.c map.c controller.c validation.c
OBJ_DIR = ./obj/
OBJ	=	$(SRC:%.c=$(OBJ_DIR)%.o)

# LIBFT LIBRARY
LIBFT_DIR = ./libft/
LIBFT = libft.a

# -L "folder" to looks for library in the folder
# -l(ft) to link library file. l replaces lib
LIB := -lft -L./libft

# HEADER
INC_DIR = ./
INC		=	$(INC_DIR)

# COMPILATION
CC			=	gcc
# CFLAGS		=	-Wall -Wextra -Werror

# REMOVE FILES OR DIRECTORIES
RM = rm -f
RMDIR = rmdir

# PRETTY
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ ${CC} -Ilibft -lmlx -framework OpenGL -framework AppKit ${OBJ} ${LIB} -o $@ #-fsanitize=address
	@ printf "$(_SUCCESS) Window startup\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ printf "$(_INFO) Libft object directory created.\n"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

map0:
	@ ./so_long map/map0.ber

map1:
	@ ./so_long map/map1.ber
	
map2:
	@ ./so_long map/map2.ber

map3:
	@ ./so_long map/map3.ber

map4:
	@ ./so_long map/map4.ber

map5:
	@ ./so_long map/map5.ber

widemap:
	@ ./so_long map/widemap.ber
	
highmap:
	@ ./so_long map/highmap.ber
	
maxmap:
	@ ./so_long map/maxmap.ber
	
clean:
	@ $(RM) $(OBJ)
	@ $(RMDIR) $(OBJ_DIR)
	@ printf "$(_INFO) Object files & directory removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) Window cache cleared.\n"

re: fclean all

.PHONY: all clean fclean re
