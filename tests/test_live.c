/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** unit tests for live instruction
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <corewar.h>

Test(live_instruction, simple_test, .init=cr_redirect_stdout)
{
    hero_t hero = {
        .cycle_to_die = CYCLE_TO_DIE,
        .name = "Test",
        .nb = 0
    };
    program_t prog = {
        .pc = 0
    };
    live_instruction(NULL, &hero, &prog, NULL);
    cr_assert_stdout_eq_str("The player0(Test)is alive.\n");
}
