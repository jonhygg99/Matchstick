/*
** EPITECH PROJECT, 2019
** ia_master
** File description:
**
*/

#include "my.h"

int simple_game(basic_t basic)
{
    int rand_line;
    int rand_match;

    srand(time(NULL));
    while (1) {
        rand_line = (rand() % (basic.lines + 1));
        if (rand_line <= basic.lines && basic.matches[rand_line] != 0 &&    \
            rand_line != 0)
            break;
    }
    while (1) {
        rand_match = (rand() % basic.nb_matches);
        if (basic.matches[rand_line] >= rand_match &&
            rand_match <= basic.nb_matches && rand_match != 0)
            break;
    }
    basic.matches[0] -= rand_match;
    basic.matches[rand_line] -= rand_match;
    ia_message_remove(rand_match, rand_line);
    print_updated_board_game(basic.board, rand_line, rand_match, basic.lines);
}

int checkmate_one_line(basic_t basic, int *stats)
{
    int i;
    int j;
    int line;
    int pipes = 0;
    int remove = 1;

    if (stats[0] == 1 && (stats[1] - basic.nb_matches) <= 1)
        remove = stats[1] - 1;
    for (i = 0; i <= basic.lines + 1; i++) {
        for (j = 0; j <= basic.lines * 2 + 2; j++) {
            if (basic.board[i][j] == '|')
                pipes++;
        }
        if (pipes != 0)
            line = i - 1;
    }
    remove_board(remove, line, basic);
    return (1);
}

int checkmate_two_line(basic_t basic, int *stats)
{
    int *check = check_two_line(basic.board, basic.lines, basic.nb_matches);
    int line = check[3];
    int remove = 1;

    if (stats[1] <= (basic.nb_matches * 2)) {
        if (check[0] > basic.nb_matches) {
            remove = check[2];
            line = check[3];
        } else if (check[0] < basic.nb_matches) {
            remove = check[0];
            line = check[1];
        } else {
            remove = check[0] - 1;
            line = check[1];
        }
    } else {
        if (check[0] == 1)
            line = check[1];
    }
    remove_board(remove, line, basic);
}

int checkmate_game(basic_t basic, int *stats)
{
    if (stats[0] == 1) {
        checkmate_one_line(basic, stats);
    } else if (stats[0] == 2) {
        checkmate_two_line(basic, stats);
    }
}

int ia_master(basic_t basic)
{
    int *stats = strategy_game(basic.board, basic.lines);

    my_putstr("AI's turn...\n");
    if (stats[0] <= 2 && basic.nb_matches != 1 && stats[0] != 0) {
        checkmate_game(basic, stats);
    } else {
        simple_game(basic);
    }
    free(stats);
}

