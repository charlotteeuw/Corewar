/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** Unit tests for fork instruction
*/
#include <criterion/criterion.h>
#include <corewar.h>

Test(fork_instruction, child_five_bytes_forward)
{
    char core[] = {0x0c, 0, 5};
    hero_t hero = {
        .programs = NULL
    };
    program_t prog = {
        .pc = 0,
        .cycle_to_next = 0,
        .carry = 0
    };
    program_t *new_prog;
    fork_instruction(NULL, &hero, &prog, core);
    new_prog = hero.programs->data;
    cr_assert_eq(new_prog->pc, 5);
}
