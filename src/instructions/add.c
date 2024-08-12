/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** add.c
*/

#include <corewar.h>

int add_instruction(hero_t **, hero_t *, program_t *prog, char *core)
{
    unsigned char params[3];
    int numbers[3];
    char coding_byte = core[(prog->pc + 1) % MEM_SIZE];

    params[0] = core[(prog->pc + 2) % MEM_SIZE];
    params[1] = core[(prog->pc + 3) % MEM_SIZE];
    params[2] = core[(prog->pc + 4) % MEM_SIZE];
    if (coding_byte != 0b01010100 || params[0] > 15 ||
        params[1] > 15 || params[2] > 15) {
        return 1;
    }
    prog->pc += 5;
    my_memcpy(&numbers[0], prog->reg[params[0] - 1], REG_SIZE);
    reverse(&numbers[0], REG_SIZE);
    my_memcpy(&numbers[1], prog->reg[params[1] - 1], REG_SIZE);
    reverse(&numbers[1], REG_SIZE);
    numbers[2] = numbers[0] + numbers[1];
    my_memcpy(prog->reg[params[2] - 1],
        reverse(&numbers[2], REG_SIZE), REG_SIZE);
    return 0;
}
