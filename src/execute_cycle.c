/*
** EPITECH PROJECT, 2024
** execute_cycle.c
** File description:
** execute.c
*/

#include <corewar.h>

int (*const INSTRUCTIONS[16])(hero_t **, hero_t *, program_t *, char *) = {
    live_instruction,
    ld_instruction,
    st_instruction,
    add_instruction,
    sub_instruction,
    and_instruction,
    or_instruction,
    xor_instruction,
    zjmp_instruction,
    ldi_instruction,
    sti_instruction,
    fork_instruction,
    lld_instruction,
    lldi_instruction,
    lfork_instruction,
    aff_instruction,
};

static size_t op_tab_len(void)
{
    size_t i = 0;

    while (op_tab[i].mnemonique != NULL)
        i++;
    return i;
}

static void exec_prog(hero_t **heros,
    char *core, program_t *prog, hero_t *hero)
{
    int len = op_tab_len();
    int instruction = core[prog->pc % MEM_SIZE];

    if (1 <= instruction && instruction <= len) {
        prog->cycle_to_next = op_tab[instruction -1].nbr_cycles;
        INSTRUCTIONS[instruction - 1](heros, hero, prog, core);
    } else {
        prog->pc++;
    }
}

static void remove_from_array(hero_t ***heros, int i)
{
    while ((*heros)[i]) {
        (*heros)[i] = (*heros)[i + 1];
        i++;
    }
}

static int update_hero(hero_t **heros, char *core, hero_t *hero)
{
    list_t *curr = hero->programs;
    program_t *prog;

    if (hero->cycle_to_die <= 0) {
        return 0;
    }
    while (curr != NULL) {
        prog = curr->data;
        if (prog->cycle_to_next <= 0) {
            exec_prog(heros, core, hero->programs->data, hero);
        } else {
            prog->cycle_to_next -= 1;
        }
        curr = curr->next;
    }
    hero->cycle_to_die -= 1;
    return 1;
}

int execute_cycle(char *core, hero_t **heros)
{
    for (int i = 0; heros[i]; i++) {
        if (update_hero(heros, core, heros[i]) == 0) {
            remove_from_array(&heros, i);
            return -1;
        }
    }
    return 0;
}
