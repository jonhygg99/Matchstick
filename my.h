/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** 
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

struct basic_s {
    char **board;
    int lines;
    int nb_matches;
    int *matches;
};
typedef struct basic_s basic_t;

struct cs_s {
    int line;
    int pipes
};
typedef struct cs_s cs_t;

int *strategy_game(char **board, int lines);
void print_updated_board_game(char **board, int line, int nb_matches, int lines);
void remove_cs(char *column, char *nb, basic_t basic);
int talk_game(basic_t basic);
int *check_two_line(char **board, int lines, int nb_matches);
void ia_message_remove(int match, int line);
int ia_master(basic_t basic);
int remove_board(int remove, int line, basic_t basic);
int my_atoi(char *str);
void my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
char *get_one_line(void);
void my_put_nbr(int nb);

#endif
