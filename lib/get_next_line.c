/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** 
*/

#include "../my.h"

char *get_one_line(void)
{
    char *buff = NULL;
    char *save;
    int j = 0;

    buff = malloc(sizeof(char) * 2);
    save = malloc(sizeof(char) * 1000000);
    while (read(0, buff, 1)) {
        if (buff[0] != '\n')
            save[j++] = buff[0];
        else {
            save[j] = '\0';
            free(buff);
            return (save);
        }
    }
    free(save);
    free(buff);
    return (NULL);
}
