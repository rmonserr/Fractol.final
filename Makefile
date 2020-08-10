# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 14:59:56 by rmonserr          #+#    #+#              #
#    Updated: 2020/03/07 15:00:00 by rmonserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCDIR = ./src
INCDIR = ./includes
OBJDIR = ./obj

SRC = error.c init.c key_managment.c main.c mandelbrot.c struct.c movement.c julia.c color.c burning_ship.c \

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MLX = ./miniLibX_X11/
MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "Compilation of Fractol:	\033[1;32mOK\033[m"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean
	@echo "Fractol: \033[1;32mRemoving Objs\033[m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@echo "Fractol : \033[1;32mRemoving Fractol\033[m"

re: fclean all

.PHONY: all clean fclean re
