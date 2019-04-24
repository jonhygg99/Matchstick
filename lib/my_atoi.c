/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** char to int
*/

int my_atoi(char *str)
{
    int nb = 0;
    int negative = 1;

    while (*str >= '0' && *str <= '9') {
        nb *= 10;
        nb += *str - 48;
        str++;
    }
    nb = nb * negative;
    return (nb);
}
