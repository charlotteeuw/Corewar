/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** ldi.c
*/

#include <corewar.h>

static int read_first(program_t *prog, char *core, char coding_byte, int pc)
{
    int param = 0;

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

static int read_second(program_t *prog, char *core, char coding_byte, int pc)
{
    int param = 0;

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

int ldi_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    char coding_byte;
    int pc = prog->pc;
    int param1 = 0;
    int param2 = 0;
    unsigned char param3;
    int result = 0;

    coding_byte = core[(pc + 1) % MEM_SIZE];
    prog->pc += 2;
    param1 = read_first(prog, core, coding_byte, pc);
    param2 = read_second(prog, core, coding_byte, pc);
    param3 = read_parameter(core, prog, REG_SIZE);
    result = param1 + param2;
    my_memcpy(&prog->reg[param3 - 1],
        &core[(pc + result % IDX_MOD) % MEM_SIZE], REG_SIZE);
    return 0;
}
