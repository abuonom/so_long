# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 19:15:40 by abuonomo          #+#    #+#              #
#    Updated: 2023/03/16 15:10:12 by abuonomo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c\
					check_map.c\
					init_map.c\
					gameplay.c\
					movement.c\
					image_builder.c\
					enemy_animations.c\
					exit_code.c\
					moves_print.c\
					free_code.c\

HEADER			=	./so_long.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

NAME			=	so_long

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror

MLX_FLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)
				$(CC) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

clean:
				@${RM} ${OBJECTS}
				@make clean -C ${LIBFT_PATH}
				@make clean -C ${MINILIBX_PATH}

fclean:			clean
					@rm -f $(NAME)
					@rm -f $(MINILIBX)
					@rm -f $(LIBFT)

re:				fclean all

.PHONY:			all clean re
