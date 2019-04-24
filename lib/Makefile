##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_atoi.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		get_next_line.c	\
		my_put_nbr.c	\
		my_putnbr_base.c	\
		my_itoa.c	\
		my_revstr.c	\
		my_swap_char.c	\

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
