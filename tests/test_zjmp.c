/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** unit test for zjmp instruction
*/
#include <criterion/criterion.h>
#include <corewar.h>

Test(zjmp_instruction, jump_forward)
{
    char core[] = {0x09, 0, 2};
    program_t prog = {
        .pc = 0,
        .carry = 1
    };
    zjmp_instruction(NULL, NULL, &prog, core);
    cr_assert_eq(prog.pc, 2);
}

Test(zjmp_instruction, no_carry)
{
    program_t prog = {
        .pc = 0,
        .carry = 0
    };
    int status = zjmp_instruction(NULL, NULL, &prog, NULL);
    cr_assert_eq(status, 0);
}
