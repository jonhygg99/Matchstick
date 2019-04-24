/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** converts and returns the base
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_atoi(char *str);
int my_putchar(char);
void my_putstr(char*);
char *my_revstr(char *str);

char my_change(char rip, char const *base)
{
    int i = 0;
    char *tmp;
    int len;
    
    len = my_strlen(base);
    tmp = malloc(sizeof(char) * len);
    i = 0;
    while(i < len) {
        tmp[i] = i + 48;
        if (rip == tmp[i]) {
            rip = base[i];
            return (rip);
        }
        i++;
    }
    free(tmp);
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    int i = 0;
    int len;
    char *result;
    int mod = 0;
    char rip;
    int nb_result;

    result = malloc(sizeof(char) * 100);
    len = my_strlen(base);
    for (nbr; nbr != 0 ; nbr /= len) {
        mod = nbr % len;
        rip = mod + '0';
        result[i] = my_change(rip, base);
        i++;
    }
    result = my_revstr(result);
    nb_result = my_atoi(result);
    return (nb_result);
}
