/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** reverse the string
*/

int my_strlen(char const *str);
int my_swap_char(char *a, char *b);

char *my_revstr(char *str)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = my_strlen(str) - 1;

    while (j > i) {
        my_swap_char(&str[i], &str[j]);
        j--;
        i++;
    }
    return (str);
}
