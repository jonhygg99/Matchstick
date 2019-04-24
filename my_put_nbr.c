/*                                                                            
** EPITECH PROJECT, 2018                                                      
** my_put_nbr                                                                 
** File description:                                                          
** print int                                                                  
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int i;
    int num;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb % 10 + '0');
    }
}
