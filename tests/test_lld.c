/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** Unit tests for lld instruction
*/
#include <criterion/criterion.h>
#include <corewar.h>

Test(lld_instruction, load_direct_value)
{
    char core[] = {0x02, 0b10010000, 0, 0, 0, 5, 1};
    program_t prog = {
        .carry = 0,
        .pc = 0,
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    lld_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[0][0], 5);
}

Test(lld_instruction, load_direct_value_with_carry)
{
    char core[] = {0x02, 0b10010000, 0, 0, 0, 5, 1};
    program_t prog = {
        .carry = 1,
        .pc = 0,
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    lld_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[0][0], 5);
}

Test(lld_instruction, load_indirect_value)
{
    char core[] = {0x02, 0b11010000, 0, 5, 1, 0x10, 0, 0, 0};
    program_t prog = {
        .carry = 0,
        .pc = 0,
    };
    for (size_t x = 0; x < REG_NUMBER; x++) {
        for (size_t y = 0; y < REG_SIZE; y++) {
            prog.reg[x][y] = 0;
        }
    }
    lld_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[0][0], 0x10);
}

Test(lld_instruction, bad_parameters)
{
    char core[] = {0x02, 0b01010000, 0, 5, 1, 0x10, 0, 0, 0};
    program_t prog = {
        .carry = 0,
        .pc = 0,
    };
    int status = 0;
    status = lld_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(status, 1);
}
