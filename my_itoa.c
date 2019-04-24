/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** int to char
*/

#include <stdlib.h>

char *my_revstr(char *str);
int my_swap_char(char *a, char *b);

char *my_itoa(int nb)
{
    int i;
    int tmp = nb;
    int nb2 = nb;
    char *str;

    if (tmp < 0)
        tmp = -tmp;
    for (i = 1; tmp > 0; i++)
        tmp /= 10;
    str = malloc(sizeof(char) * (i + 2));
    if (nb < 0)
        nb = -nb;
    for (i = 0; nb > 0; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    if (nb2 < 0)
        str[i] = '-';
    str = my_revstr(str);
    return (str);
}
