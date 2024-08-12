/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** sti.c
*/

#include <corewar.h>

static int read_second(int param, program_t *prog, char *core,
    char coding_byte)
{
    int pc = prog->pc;

    switch (SECOND_PARAM_TYPE(coding_byte)) {
        case 0b01:
            param = read_parameter(core, prog, 1);
            my_memcpy(&param, prog->reg[param - 1], REG_SIZE);
            break;
        case 0b10:
            param = read_parameter(core, prog, IND_SIZE);
            break;
        case 0b11:
            param = read_parameter(core, prog, IND_SIZE);
            my_memcpy(&param,
                &core[(pc + param % IDX_MOD) % MEM_SIZE], REG_SIZE);
            break;
    }
    return param;
}

static int read_third(int param, program_t *prog, char *core, char coding_byte)
{
    int pc = prog->pc;

    switch (THIRD_PARAM_TYPE(coding_byte)) {
        case 0b01:
            param = read_parameter(core, prog, 1);
            my_memcpy(&param, prog->reg[param - 1], REG_SIZE);
            break;
        case 0b10:
            param = read_parameter(core, prog, IND_SIZE);
            break;
        case 0b11:
            param = read_parameter(core, prog, IND_SIZE);
            my_memcpy(&param,
                &core[(pc + param % IDX_MOD) % MEM_SIZE], REG_SIZE);
            break;
    }
    return param;
}

int sti_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    char coding_byte;
    unsigned char param1;
    int param2 = 0;
    int param3 = 0;
    int pc = prog->pc;

    prog->pc++;
    coding_byte = core[prog->pc % MEM_SIZE];
    prog->pc++;
    param1 = read_parameter(core, prog, 1);
    param2 = read_second(param2, prog, core, coding_byte);
    param3 = read_third(param3, prog, core, coding_byte);
    my_memcpy(&core[(pc + (param2 + param3) % IDX_MOD) % MEM_SIZE],
        prog->reg[param1 - 1], REG_SIZE);
    return 0;
}
