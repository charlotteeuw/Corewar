/*
** EPITECH PROJECT, 2024
** .h
** File description:
** Header file for Corewar
*/

#ifndef COREWAR_H
    #define COREWAR_H

    #include <op.h>
    #include <lib.h>

    #include <sys/stat.h>
    #include <fcntl.h>

    #define MAX_NB_HEROS 6
    #define MAX_HERO_SIZE 1024

    #define FIRST_PARAM_TYPE(coding_byte) ((coding_byte & 0b11000000) >> 6)
    #define SECOND_PARAM_TYPE(coding_byte) ((coding_byte & 0b00110000) >> 4)
    #define THIRD_PARAM_TYPE(coding_byte) ((coding_byte & 0b00001100) >> 2)
    #define FOURTH_PARAM_TYPE(coding_byte) ((coding_byte & 0b00000011) >> 0)

    #define REG_TYPE 0b01
    #define DIR_TYPE 0b10
    #define IND_TYPE 0b11
    #define OTH_TYPE 0b00

    #define HEX "0123456789ABCDEF"
    #define MY_MIN(x, y) ((x < y) ? (x) : (y))

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

typedef struct program_s {
    char reg[REG_NUMBER][REG_SIZE];
    int pc;
    int carry;
    int cycle_to_next;
} program_t;

typedef struct hero_s {
    char *name;
    size_t prog_size;
    char *prog;
    int nb;
    int adress;
    int cycle_to_die;
    list_t *programs;
} hero_t;

extern int (*const INSTRUCTIONS[16])(hero_t **, hero_t *, program_t *, char *);

int usage(char *param);
int error(int ac, char **av);
void corewar(char **argv);

void *reverse(void *ptr, size_t size);
int read_parameter(char *core, program_t *prog, size_t size);

//extract_heros.c

int count_heros(char **argv);
hero_t **get_heros(char **argv, int nb_heros);

//dump_core.c

void dump_core(char *core);

//execute_cycle.c

int execute_cycle(char *core, hero_t **heros);

//instructions without coding byte

int live_instruction(hero_t **heros, hero_t *, program_t *prog, char *core);
int zjmp_instruction(hero_t **, hero_t *hero, program_t *prog, char *core);
int fork_instruction(hero_t **, hero_t *hero, program_t *prog, char *core);
int lfork_instruction(hero_t **, hero_t *hero, program_t *prog, char *core);

//instructions with coding byte

int ld_instruction(hero_t **, hero_t *hero, program_t *prog, char *core);
int st_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int add_instruction(hero_t **, hero_t *hero, program_t *prog, char *core);
int sub_instruction(hero_t **, hero_t *hero, program_t *prog, char *core);
int and_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int or_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int xor_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int ldi_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int sti_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int lld_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int lldi_instruction(hero_t **, hero_t *, program_t *prog, char *core);
int aff_instruction(hero_t **, hero_t *, program_t *prog, char *core);

#endif /* !COREWAR_H */
