/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** Unit tests for aff instruction
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <corewar.h>

Test(aff_instruction, display_star, .init=cr_redirect_stdout)
{
    char core[] = {0x10, 0b01000000, 3};
    program_t prog = {
        .pc = 0,
    };
    prog.reg[2][0] = 42;
    aff_instruction(NULL, NULL, &prog, core);
    cr_assert_stdout_eq_str("*");
}
