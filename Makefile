# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 01:50:00 by antigravity       #+#    #+#              #
#    Updated: 2025/12/09 01:50:00 by antigravity      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
NAME_BONUS  = so_long_bonus

# Paths
LIBFT_DIR   = libft
INC_DIR     = include

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a
MLX_LIB     = ./libmlx42.a

# Compilation
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -I. -I$(INC_DIR) -I$(LIBFT_DIR)
MLX_FLAGS   = $(MLX_LIB) -ldl -lglfw -pthread -lm
RM          = rm -f

# Source Files
SRC         = src/main.c src/check_map.c src/init.c src/init_utils.c src/render.c src/map.c \
              src/flood_fill.c src/flood_fill_utils.c src/hooks.c src/movement.c src/animation.c src/utils.c \
              src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c

SRC_BONUS   = bonus/main_bonus.c bonus/check_map_bonus.c bonus/check_map_utils_bonus.c \
              bonus/init_bonus.c bonus/init_utils_bonus.c bonus/render_bonus.c \
              bonus/render_utils_bonus.c \
              src/map.c src/flood_fill.c src/flood_fill_utils.c bonus/hooks_bonus.c bonus/movement_bonus.c \
              bonus/animation_bonus.c bonus/enemy_init.c bonus/enemy_move.c \
              bonus/bonus_utils.c bonus/reset_utils.c src/utils.c bonus/menu.c bonus/menu_utils.c bonus/music.c \
              src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c

# Object Files
OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

# Colors
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

all: $(NAME)

# Compiling Mandatory
$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@printf "$(GREEN)so_long compiled$(RESET)\n"

# Bonus Rules
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)
	@printf "$(GREEN)so_long_bonus compiled$(RESET)\n"

# Compiling Libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Pattern Rule for Objects
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@printf "$(YELLOW)Objects cleaned$(RESET)\n"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "$(YELLOW)Executables cleaned$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus