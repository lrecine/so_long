# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 14:42:15 by lrecine-          #+#    #+#              #
#    Updated: 2025/03/10 15:56:39 by lrecine-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Werror -Wextra -g3
CC		= cc $(CFLAGS)
MLX		= -lmlx -lXext -lX11
#MLX_DIR = minilibx-linux
#MLX_INC = -I$(MLX_DIR)
#MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11
NAME =	so_long
LIBFT =	libft/libft.a
SRCS =	ft_check_error.c ft_check_map.c ft_draw_map.c ft_handle_event.c ft_handle_images.c \
		ft_handle_map.c ft_handle_enemy.c ft_player_moves.c ft_enemy_moves.c so_long.c ft_route_map.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)

%.o: %.c
	$(CC) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re