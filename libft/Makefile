CFILES = *.c
OFILES = *.o

NAME = libft.a

all:	$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -std=c99 -c $(CFILES) 
	ar rc $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re:		fclean all
