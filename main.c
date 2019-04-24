/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** 
*/

#include "my.h"

char **malloc_board(int lines)
{
    int i;
    char **map = (char **) malloc((lines + 1) * sizeof(char *));

    for (i = 0; i <= lines + 1; i++)
        map[i] = (char *) malloc((lines * 2 + 2) * sizeof(char));
    map[i] = NULL;
    return (map);
}

char **add_stars(char **map, int lines, int l)
{
    int j;
    int max = lines * 2;

    for (j = 0; j <= max; j++)
        map[0][j] = '*';
    for (j = 0; j <= max; j++)
        map[lines + 1][j] = '*';
    return (map);
}

char **game_board(int lines)
{
    int i;
    int j;
    int l = 0;
    char **map = malloc_board(lines);
    int pipes = 1;

    for (i = 1; i <= lines; i++) {
        l = 0;
        map[i][l++] = '*';
        for (j = 0; j < (lines - i); j++)
            map[i][l++] = ' ';
        for (j = 0; j < pipes; j++)
            map[i][l++] = '|';
        for (j = 0; j < (lines - i); j++)
            map[i][l++] = ' ';
        map[i][l++] = '*';
        pipes += 2;
    }
    map = add_stars(map, lines, l);
    return (map);
}

int *count_matches(int lines)
{
    int i;
    int *matches = malloc(sizeof(int) * lines + 1);
    int pipes = 1;
    int max = 0;

    for (i = 1; i <= lines; i++) {
        matches[i] = pipes;
        max += pipes;
        pipes += 2;
    }
    matches[0] = max;
}

int main(int ac, char **ag)
{
    int j;
    basic_t basic;

    if (ac < 3 || ac > 4) {
        return (84);
    } else if (my_atoi(ag[1]) >= 1 && my_atoi(ag[1]) <= 100 &&\
                my_atoi(ag[2]) >= 1) {
        basic.board = game_board(my_atoi(ag[1]));
        basic.lines = my_atoi(ag[1]);
        basic.nb_matches = my_atoi(ag[2]);
        basic.matches = count_matches(my_atoi(ag[1]));
        for (j = 0; j <= my_atoi(ag[1]) + 1; j++) {
            my_putstr(basic.board[j]);
            my_putchar('\n');
        }
        my_putchar('\n');
        j = talk_game(basic);
        return (j);
    } else
        return (84);
}
