/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** ld.c
*/

#include <corewar.h>

int read_parameter(char *core, program_t *prog, size_t size)
{
    int param = 0;
    char *bytes = (char *)(&param);

    for (size_t i = 0; i < size; i++) {
        bytes[size - i - 1] = core[(prog->pc + i) % MEM_SIZE];
    }
    prog->pc = (prog->pc + size) % MEM_SIZE;
    return param;
}

int ld_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    int param1 = 0;
    unsigned char param2 = 0;
    int pc = prog->pc;
    char coding_byte = core[(prog->pc + 1) % MEM_SIZE];

    prog->pc += 2;
    if (FIRST_PARAM_TYPE(coding_byte) == DIR_TYPE) {
        param1 = read_parameter(core, prog, DIR_SIZE);
        param2 = read_parameter(core, prog, 1);
        my_memcpy(prog->reg[param2 - 1], &param1, REG_SIZE);
    } else if (FIRST_PARAM_TYPE(coding_byte) == IND_TYPE) {
        param1 = read_parameter(core, prog, IND_SIZE);
        param2 = read_parameter(core, prog, 1);
        my_memcpy(prog->reg[param2 - 1],
            &core[(pc + param1 % IDX_MOD) % MEM_SIZE], REG_SIZE);
    } else {
        return 1;
    }
    return 0;
}
