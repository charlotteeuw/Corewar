/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** st.c
*/

#include <corewar.h>

int st_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    char coding_byte = 0;
    unsigned char param1 = 0;
    int param2 = 0;
    int pc = prog->pc;

    coding_byte = core[(prog->pc + 1) % MEM_SIZE];
    prog->pc += 2;
    param1 = read_parameter(core, prog, 1);
    switch (SECOND_PARAM_TYPE(coding_byte)) {
        case 0b01:
            param2 = read_parameter(core, prog, 1);
            my_memcpy(prog->reg[param2 - 1], prog->reg[param1 - 1], REG_SIZE);
            break;
        case 0b11:
            param2 = read_parameter(core, prog, IND_SIZE);
            my_memcpy(&core[(pc + param2 % IDX_MOD) % MEM_SIZE],
                prog->reg[param1 - 1], REG_SIZE);
            break;
    }
    return 0;
}
