/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** unit test for sub instruction
*/
#include <criterion/criterion.h>
#include <corewar.h>

Test(sub_instruction, subs_correctly)
{
    char core[] = {0x04, 0b01010100, 1, 2, 3};
    program_t prog = {
        .pc = 0,
        .carry = 0,
        .cycle_to_next = 0
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    prog.reg[0][0] = 1;
    prog.reg[1][0] = 5;
    sub_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[2][0], -4);
}
