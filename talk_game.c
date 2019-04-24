/*
** EPITECH PROJECT, 2019
** talk_game
** File description:
** 
*/

#include "my.h"

void print_updated_board_game(char **board, int line, int nb_matches,
                                int lines)
{
    int i;
    int len = my_strlen(board[line]);

    for (i = len; i >= 1; i--) {
        if (board[line][i] == '|' && nb_matches > 0) {
            board[line][i] = ' ';
            nb_matches--;
        }
    }
    for (i = 0; i <= lines + 1; i++) {
        my_putstr(board[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

char *line_speaks(char *column, int lines, int *matches)
{
    while (1) {
        my_putstr("Line: ");
        column = get_one_line();
        if (column == NULL) {
            return (column);
        }
        if (my_atoi(column) > lines || my_atoi(column) <= 0)
            my_putstr("Error: this line is out of range\n");
        else if (matches[my_atoi(column)] == 0)
            my_putstr("Error: no more matches in this line\n");
        else
            return (column);
    }
}

void player_message_remove(int match, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

char *matches_speaks(char *nb, int *matches, char *column, int nb_matches)
{
    while (1) {
        my_putstr("Matches: ");
        nb = get_one_line();
        if (nb == NULL)
            return (nb);
        if (my_atoi(nb) <= 0) {
            my_putstr("Error: you have to remove at least one match\n");
            return ("0");
        } else if (nb_matches < my_atoi(nb)) {
            my_putstr("Error: you set the limit of removing matches in ");
            my_put_nbr(nb_matches);
            my_putchar('\n');
            return ("0");
        } else if (matches[my_atoi(column)] < my_atoi(nb)) {
            my_putstr("Error: not enough matches on this line\n");
            return ("0");
        } else {
            player_message_remove(my_atoi(nb), my_atoi(column));
            return (nb);
        }
    }
}

int talk_game(basic_t basic)
{
    char *nb = malloc(sizeof(char) * 4);
    char *column  = malloc(sizeof(char) * 4);

    while (1) {
        column = line_speaks(column, basic.lines, basic.matches);
        nb = matches_speaks(nb, basic.matches, column, basic.nb_matches);
        if (column == NULL || nb == NULL) {
            my_putstr("Sorry you loose!\n");
            return (0);
        } else if (my_atoi(nb) != 0) {
            print_updated_board_game(basic.board, my_atoi(column),
                                    my_atoi(nb), basic.lines);
            remove_cs(column, nb, basic);
            if (basic.matches[0] == 0)
                return (2);
            ia_master(basic);
            if (basic.matches[0] == 0)
                return (1);
        }
    }
}
