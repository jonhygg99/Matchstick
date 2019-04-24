##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		my_atoi.c	\
		my_putchar.c	\
		my_putstr.c	\
		talk_game.c	\
		my_strlen.c	\
		get_next_line.c	\
		my_put_nbr.c	\
		ia_turn.c	\
		my_putnbr_base.c	\
		my_itoa.c	\
		my_revstr.c	\
		my_swap_char.c	\
		ia_master.c	\
		check_game.c	\
		remove_cs.c

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
