/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** live.c
*/

#include <corewar.h>

static void print_hero(hero_t *hero)
{
    my_putstr("The player ");
    my_put_nbr(hero->nb);
    my_putchar('(');
    my_putstr(hero->name);
    my_putstr(")is alive.\n");
}

int live_instruction(hero_t **heros, hero_t *, program_t *prog, char *core)
{
    static int cycle_to_die = CYCLE_TO_DIE;
    static int nbr_live = 0;
    int param = 0;

    prog->pc++;
    param = read_parameter(core, prog, 4);
    if (nbr_live == NBR_LIVE) {
        cycle_to_die -= CYCLE_DELTA;
        nbr_live = 0;
    }
    for (size_t i = 0; heros[i]; i++) {
        if (heros[i]->nb == param) {
            heros[i]->cycle_to_die = cycle_to_die;
            print_hero(heros[i]);
        }
    }
    nbr_live++;
    return 0;
}
