/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** zjmp.c
*/

#include <corewar.h>

int zjmp_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    size_t i = 0;
    int value = 0;
    int pc = prog->pc;

    if (prog->carry == 0)
        return 0;
    pc++;
    while (i < IND_SIZE) {
        value *= 0x100;
        value = core[(pc + i) % MEM_SIZE];
        i++;
    }
    prog->pc = prog->pc + value % IDX_MOD;
    return 0;
}
