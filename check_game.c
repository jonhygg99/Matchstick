/*
** EPITECH PROJECT, 2019
** strategy
** File description:
** strategy
*/

#include "my.h"

int *check_two_line(char **board, int lines, int nb_matches)
{
    int i;
    int j;
    int k = 0;
    int *check = malloc(sizeof(int *) * 5);
    int pipes = 0;

    for (i = 0; i <= lines; i++) {
        for (j = 0; j <= lines * 2 + 2; j++) {
            if (board[i][j] == '|')
                pipes++;
        }
        if (pipes != 0) {
            check[k++] = pipes;
            check[k++] = i;
            pipes = 0;
        }
    }
    return (check);
}

int count_lines_pipes(char **board, int lines, int troya)
{
    int count = 0;
    int pipes = 0;
    int i;
    int j;

    for (i = 1; i <= lines; i++) {
        for (j = 0; j <= lines * 2 + 2; j++) {
            if (board[i][j] == '|')
                pipes++;
	}
        if (pipes != 0)
            count++;
    }
    if (troya == 0)
        return (count);
    else
        return (pipes);
}

int *checkmate_game2(int *checkmate, cs_t cs, char **board, int lines)
{
    int k = 2;

    for (int i = 1; i <= lines; i++) {
        for (int j = 0; j <= lines * 2 + 2; j++)
            if (board[i][j] == '|') {
                if (cs.line == 0) {
                    cs.line++;
                    checkmate[k++] = i;
                }
                cs.pipes++;
            }
        cs.line = 0;
        if (cs.pipes != 0) {
            checkmate[k++] = cs.pipes;
            cs.pipes = 0;
        }
    }
    return (checkmate);
}

int *strategy_game(char **board, int lines)
{
    int troya = 0;
    int line_in = count_lines_pipes(board, lines, troya++);
    int pipes_in = count_lines_pipes(board, lines, troya);
    int *checkmate = malloc(sizeof(int) * (11));
    int k = 2;
    cs_t cs;
    
    cs.line = 0;
    cs.pipes = 0;
    if (line_in <= 3) {
        checkmate = checkmate_game2(checkmate, cs, board, lines);
        checkmate[0] = line_in;
        checkmate[1] = pipes_in;
        return (checkmate);
    }
}

int remove_board(int remove, int line, basic_t basic)
{
    if (remove == 0)
        remove = 1;
    basic.matches[0] -= remove;
    basic.matches[line] -= remove;
    ia_message_remove(remove, line);
    print_updated_board_game(basic.board, line, remove, basic.lines);
    return (remove);
}
