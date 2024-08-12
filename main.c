/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include <corewar.h>

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    if (usage(argv[1]))
        return 0;
    if (error(argc, argv))
        return 84;
    corewar(argv);
    return 0;
}
