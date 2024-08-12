/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** Unit tests for or instruction
*/
#include <criterion/criterion.h>
#include <corewar.h>

Test(or_instruction, register_and_direct_to_register_one)
{
    char core[] = {0x06, 0b01100100, 2, 0, 0, 0, 6, 1};
    program_t prog = {
        .pc = 0,
        .carry = 0
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    prog.reg[1][3] = 7;
    or_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[0][3], 7 | 6);
}

Test(or_instruction, direct_and_register_to_register_one)
{
    char core[] = {0x06, 0b10010100, 0, 0, 0, 6, 2, 1};
    program_t prog = {
        .pc = 0,
        .carry = 0
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    prog.reg[1][3] = 7;
    or_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[0][3], 7 | 6);
}

Test(or_instruction, indirect_and_indirect_to_register_one)
{
    char core[] = {0x06, 0b11110100, 0, 7, 0, 11, 1, 0, 0, 0, 6, 0, 0, 0, 7};
    program_t prog = {
        .pc = 0,
        .carry = 0
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    or_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[0][3], 6 | 7);
}

Test(or_instruction, bad_parameters)
{
    char core[] = {0x06, 0b00000100, 1};
    program_t prog = {
        .pc = 0,
        .carry = 0
    };
    int status = 0;
    status = or_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(status, 1);
}
