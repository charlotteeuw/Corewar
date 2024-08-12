/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** corewar.c
*/

#include <corewar.h>

static int get_dump(char **args)
{
    int dump = __INT_MAX__;

    if (my_strcmp(args[1], "-dump") == 0) {
        dump = my_atoi(args[2]);
    }
    return dump;
}

static void print_winner(hero_t **heros)
{
    my_putstr("The player ");
    my_put_nbr(heros[0]->nb);
    my_putchar('(');
    my_putstr(heros[0]->name);
    my_putstr(")has won.\n");
}

static void init_registers(hero_t *hero, program_t *prog)
{
    char *id = (char *)&hero->nb;

    prog->reg[0][0] = id[3];
    prog->reg[0][1] = id[2];
    prog->reg[0][2] = id[1];
    prog->reg[0][3] = id[0];
    for (size_t i = 1; i < REG_NUMBER; i++) {
        for (size_t j = 0; j < REG_SIZE; j++) {
            prog->reg[i][j] = 0;
        }
    }
}

static void put_heros_in_core(char *core, hero_t **heros, int nb_heros)
{
    program_t *prog;

    for (int i = 0; i < nb_heros; i++) {
        heros[i]->programs = malloc(sizeof(list_t));
        prog = malloc(sizeof(program_t));
        prog->pc = heros[i]->adress;
        prog->carry = 1;
        prog->cycle_to_next = 0;
        init_registers(heros[i], prog);
        heros[i]->programs->data = prog;
        heros[i]->programs->next = NULL;
        for (size_t j = 0; j < heros[i]->prog_size; j++) {
            core[(prog->pc + j) % MEM_SIZE] = heros[i]->prog[j];
        }
    }
}

static char *core_create(void)
{
    char *core = malloc(MEM_SIZE);

    for (size_t i = 0; i < MEM_SIZE; i++) {
        core[i] = 0;
    }
    return core;
}

void corewar(char **argv)
{
    int dump = get_dump(argv);
    char *core = core_create();
    int nb_heros = count_heros(argv);
    hero_t **heros = get_heros(argv, nb_heros);
    int cycle_to_dump = dump;

    put_heros_in_core(core, heros, nb_heros);
    while (nb_heros > 1) {
        if (cycle_to_dump <= 0) {
            dump_core(core);
            cycle_to_dump = dump;
        } else {
            cycle_to_dump -= 1;
        }
        nb_heros += execute_cycle(core, heros);
    }
    print_winner(heros);
}
