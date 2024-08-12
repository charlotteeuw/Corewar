/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** Unit tests for st instruction
*/
#include <criterion/criterion.h>
#include <corewar.h>

Test(st_instruction, store_first_register_into_core)
{
    char core[] = {0x03, 0b01110000, 1, 0, 3, 0, 0};
    program_t prog = {
        .pc = 0,
    };
    prog.reg[0][0] = 5;
    prog.reg[0][1] = 0;
    prog.reg[0][2] = 0;
    prog.reg[0][3] = 0;
    st_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(core[3], 5);
    cr_assert_eq(core[4], 0);
    cr_assert_eq(core[5], 0);
    cr_assert_eq(core[6], 0);
}

Test(st_instruction, store_first_register_into_second_register)
{
    char core[] = {0x03, 0b01010000, 1, 2};
    program_t prog = {
        .pc = 0,
    };
    prog.reg[0][0] = 5;
    prog.reg[0][1] = 0;
    prog.reg[0][2] = 0;
    prog.reg[0][3] = 0;
    st_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.reg[1][0], 5);
    cr_assert_eq(prog.reg[1][1], 0);
    cr_assert_eq(prog.reg[1][2], 0);
    cr_assert_eq(prog.reg[1][3], 0);
}

Test(st_instruction, bad_parameters)
{
    char core[] = {0x03, 0b01100000, 1, 2};
    program_t prog = {
        .pc = 0,
    };
    int status = 0;
    status = st_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(status, 1);
}
