/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** lld.c
*/

#include <corewar.h>

static char increment_pc(program_t *prog, char *core)
{
    char coding_byte;

    prog->pc++;
    coding_byte = core[prog->pc % MEM_SIZE];
    prog->pc++;
    return coding_byte;
}

int lld_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    char coding_byte = increment_pc(prog, core);
    int param1 = 0;
    unsigned char param2 = 0;
    int pc = prog->pc;

    switch (FIRST_PARAM_TYPE(coding_byte)) {
        case 0b10:
            param1 = read_parameter(core, prog, DIR_SIZE);
            param2 = read_parameter(core, prog, 1);
            my_memcpy(prog->reg[param2 - 1], &param1, REG_SIZE);
            break;
        case 0b11:
            param1 = read_parameter(core, prog, IND_SIZE);
            param2 = read_parameter(core, prog, 1);
            my_memcpy(prog->reg[param2 - 1],
                &core[(pc + param1) % MEM_SIZE], REG_SIZE);
            break;
    }
    return 0;
}
