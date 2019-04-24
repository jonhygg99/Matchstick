/*
** EPITECH PROJECT, 2019
** ia turn
** File description:
** 
*/

#include "my.h"

void ia_message_remove(int match, int line)
{
    my_putstr("AI's removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}
