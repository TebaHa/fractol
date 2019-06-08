# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 19:27:06 by zytrams           #+#    #+#              #
#    Updated: 2019/06/08 19:28:53 by zytrams          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -g -Wall -Wextra -Werror

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./lib/libft/
LIBFT_DIRECTORY_HEADERS = $(LIBFT_DIRECTORY)/includes

MINILIB = $(MINILIB_DIRECTORY)libmlx.a
MINILIB_DIRECTORY = ./lib/minilibx/sierra/

OBJS_DIRECTORY = ./objs/
SRCS_DIRECTORY = ./srcs/

SRCS_LIST = fractol.c

HEADERS_DIRECTORY = ./includes/

HEADERS_LIST = fractol.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
INCLUDES = -I$(HEADERS_DIRECTORY)

SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIRECTORY), $(OBJS_LIST))

OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))

all: $(NAME)

$(NAME): $(MINILIB) $(LIBFT) $(OBJS_DIRECTORY) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lmlx -framework OpenGL -framework AppKit -L lib/minilibx/ $(LIBFT) -g

$(OBJS_DIRECTORY):
	@mkdir -p $(OBJS_DIRECTORY)
	@echo "$(NAME): $(OBJS_DIRECTORY) was created"

$(OBJS_DIRECTORY)%.o: $(SRCS_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) -I $(LIBFT_DIRECTORY_HEADERS) -I $(MINILIB_DIRECTORY) $< -o $@ -g

$(MINILIB):
	@$(MAKE) -sC $(MINILIB_DIRECTORY)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@rm -rf $(OBJS_DIRECTORY)/*.o
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIB_DIRECTORY) clean


fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -sC $(LIBFT_DIRECTORY) fclean

re: fclean all
