/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** aff.c
*/

#include <corewar.h>

int aff_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    int i = 0;
    char coding_byte = core[(prog->pc + 1) % MEM_SIZE];
    unsigned char param = core[(prog->pc + 2) % MEM_SIZE];

    if (coding_byte != 0b01000000 || param > 15) {
        return 1;
    }
    prog->pc += 2;
    param = read_parameter(core, prog, 1);
    my_memcpy(&i, prog->reg[param - 1], REG_SIZE);
    my_putchar(i % 256);
    return 0;
}
