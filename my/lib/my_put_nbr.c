/*
** EPITECH PROJECT, 2023
** $MY_PUT_NBR
** File description:
** Prints a number
*/

#include <lib.h>

void positive_num(int nb)
{
    my_putchar(nb + 48);
}

int negative_num(int nb)
{
    nb *= -1;
    return nb;
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = negative_num(nb);
    }
    if (nb >= 0 && nb <= 9) {
        positive_num(nb);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return 0;
}
