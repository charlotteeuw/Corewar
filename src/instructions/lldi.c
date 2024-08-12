/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** lldi.c
*/

#include <corewar.h>

static int read_first(int param, program_t *prog, char *core, char coding_byte)
{
    int pc = prog->pc;

    switch (FIRST_PARAM_TYPE(coding_byte)) {
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

int lldi_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    char coding_byte;
    int pc = prog->pc;
    int param1 = 0;
    int param2 = 0;
    unsigned char param3;
    int result = 0;

    prog->pc++;
    coding_byte = core[prog->pc % MEM_SIZE];
    prog->pc++;
    param1 = read_first(param1, prog, core, coding_byte);
    param2 = read_second(param2, prog, core, coding_byte);
    param3 = read_parameter(core, prog, REG_SIZE);
    result = param1 + param2;
    my_memcpy(prog->reg[param3 - 1],
        &core[(pc + result) % MEM_SIZE], REG_SIZE);
    return 0;
}
