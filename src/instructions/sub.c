/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** sub.c
*/

#include <corewar.h>

int sub_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    unsigned char param1;
    unsigned char param2;
    unsigned char param3;
    int nb1;
    int nb2;
    int nb3;

    prog->pc += 2;
    param1 = core[prog->pc % MEM_SIZE];
    param2 = core[(prog->pc + 1) % MEM_SIZE];
    param3 = core[(prog->pc + 2) % MEM_SIZE];
    my_memcpy(&nb1, prog->reg[param1 - 1], sizeof(int));
    my_memcpy(&nb2, prog->reg[param2 - 1], sizeof(int));
    nb3 = nb1 - nb2;
    my_memcpy(prog->reg[param3 - 1], &nb3, sizeof(int));
    return 0;
}
