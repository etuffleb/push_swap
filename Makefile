# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 18:07:51 by etuffleb          #+#    #+#              #
#    Updated: 2019/08/15 17:44:10 by etuffleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC = checker.c \
	push_swap.c \
	operations.c \
	operations2.c \
	operations3.c \
	tools.c \
	algorithm.c

OBJ1 = $(addprefix ./obj/,$(SRC:.c=.o))
OBJ2 = $(addprefix ./obj/,$(SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g

FT_LIB	= $(addprefix ./libft/,libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME1) $(NAME2)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C ./libft

$(NAME1): $(OBJ1) $(filter-out $(NAME2).o,$(OBJ))
	gcc $(OBJ1) $(FT_LNK) -lm -o $(NAME1)
	

$(NAME2): $(OBJ2) $(filter-out $(NAME1).o,$(OBJ))
	gcc $(OBJ2) $(FT_LNK) -lm -o $(NAME2)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
