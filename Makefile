##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		talk_game.c	\
		ia_turn.c	\
		ia_master.c	\
		check_game.c	\
		remove_cs.c

NAME	=	matchstick

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)
$(NAME):	$(OBJ)
	cd lib; make; make clean; cd -;
	gcc -o $(NAME) $(OBJ) lib/libmy.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
