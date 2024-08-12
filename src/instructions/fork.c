/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** fork.c
*/

#include <corewar.h>

int fork_instruction(hero_t **, hero_t *hero, program_t *prog, char *core)
{
    program_t *new = malloc(sizeof(program_t));
    list_t *node = malloc(sizeof(list_t));
    int value = 0;
    int pc = prog->pc;

    prog->pc++;
    node->data = new;
    node->next = hero->programs;
    hero->programs = node;
    value = read_parameter(core, prog, IND_SIZE);
    new->pc = (pc + value % IDX_MOD) % MEM_SIZE;
    new->cycle_to_next = prog->cycle_to_next;
    new->carry = prog->carry;
    for (size_t i = 0; i < REG_NUMBER; i++) {
        for (size_t j = 0; j < REG_SIZE; j++) {
            new->reg[i][j] = prog->reg[i][j];
        }
    }
    return 0;
}
