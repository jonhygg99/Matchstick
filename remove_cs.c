/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "my.h"

void remove_cs(char *column, char *nb, basic_t basic)
{
    basic.matches[0] -= my_atoi(nb);                                  
    basic.matches[my_atoi(column)] -= my_atoi(nb);                   
}
