/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** Unit tests for add instruction
*/

#include <criterion/criterion.h>
#include <corewar.h>

Test(add_instruction, adds_correctly)
{
    char core[] = {0x04, 0b01010100, 1, 2, 3};
    program_t prog = {
        .pc = 0,
        .carry = 0,
        .cycle_to_next = 0
    };

    for (size_t i = 0; i < REG_NUMBER; i++) {
        for (size_t j = 0; j < REG_SIZE; j++) {
            prog.reg[i][j] = 0;
        }
    }
    prog.reg[0][0] = 1;
    prog.reg[1][0] = 5;
    add_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[2][0], 6);
}
