/*
** EPITECH PROJECT, 2018
** my_swap_char
** File description:
** swap char
*/

int my_swap_char(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
