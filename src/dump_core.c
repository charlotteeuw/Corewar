/*
** EPITECH PROJECT, 2024
** dump_core.c
** File description:
** dump_core.c
*/

#include <corewar.h>

static void my_putbyte(unsigned char nb)
{
    char *base = HEX;
    size_t size = my_strlen(base);

    my_putchar(base[nb / size]);
    my_putchar(base[nb % size]);
}

static void dump_adress(size_t adress)
{
    my_putbyte(adress >> 8 * 3);
    my_putbyte(adress >> 8 * 2);
    my_putbyte(adress >> 8 * 1);
    my_putbyte(adress >> 8 * 0);
    my_putstr("  ");
}

static int dump_line(char *core, size_t adress, int star)
{
    int dump = 0;

    for (size_t i = adress; i < adress + 32; i++) {
        if (core[i] != 0)
            dump = 1;
    }
    if (!dump) {
        return 0;
    }
    if (star) {
        my_putstr("*\n");
    }
    dump_adress(adress);
    for (size_t i = adress; i < adress + 32; i++) {
        my_putbyte(core[i]);
        my_putchar(' ');
    }
    my_putchar('\n');
    return 1;
}

void dump_core(char *core)
{
    size_t adress = 0;
    int star = 0;

    my_putstr("**************DUMP START**************\n");
    while (adress + 31 < MEM_SIZE) {
        star = !dump_line(core, adress, star);
        adress += 32;
    }
    my_putstr("***************DUMP END***************\n");
}
