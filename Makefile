# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 14:42:15 by lrecine-          #+#    #+#              #
#    Updated: 2025/01/23 15:19:31 by lrecine-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Werror -Wextra -g
CC		= cc $(CFLAGS)
MLX		= -lmlx -lXext -lX11

NAME =	so_long
LIBFT =	libft/libft.a

SRC = ft_check_error.c ft_check_map.c ft_draw_map.c ft_handle_event.c ft_handle_images.c \
		ft_handle_map.c ft_handle_trap.c ft_player_moves.c ft_trap_moves.c so_long.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	@make -C libft

%.o: %.c
	$(CC) -c $^

clean:
	rm -rf $(OBJ)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re