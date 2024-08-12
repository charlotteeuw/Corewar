/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** error_handling.c
*/

#include <corewar.h>

static int wrong_number_heros(char **args)
{
    int nb_heros = count_heros(args);

    if (nb_heros < 2) {
        my_puterr("Too few heros, provide at least 2\n");
        return 1;
    }
    if (nb_heros > MAX_NB_HEROS) {
        my_puterr("Too many heros\n");
        return 1;
    }
    return 0;
}

static int number_error(char **argv, size_t *i)
{
    if (my_strcmp(argv[*i], "-n") == 0) {
        if (argv[*i + 1] == NULL || !my_str_isnum(argv[*i + 1])) {
            return 1;
        }
        *i += 2;
    }
    return 0;
}

static int adress_error(char **argv, size_t *i)
{
    if (my_strcmp(argv[*i], "-a") == 0) {
        if (argv[*i + 1] == NULL || !my_str_isnum(argv[*i + 1])) {
            return 1;
        }
        *i += 2;
    }
    return 0;
}

static int file_error(char **argv, size_t *i)
{
    struct stat file;

    if (stat(argv[*i], &file) == -1) {
        my_puterr(argv[*i]);
        my_puterr(": file does not exist, or cannot be open\n");
        return 1;
    }
    if (file.st_size < (long)sizeof(header_t)) {
        my_puterr(argv[*i]);
        my_puterr(": file must at least contain a header\n");
        return 1;
    }
    if (file.st_size > (long)sizeof(header_t) + MAX_HERO_SIZE) {
        my_puterr(argv[*i]);
        my_puterr(": hero must be shorter than 1024 bytes\n");
        return 1;
    }
    *i += 1;
    return 0;
}

static int invalid_arg(char **argv)
{
    size_t i = 1;

    if (my_strcmp(argv[1], "-dump") == 0) {
        if (!my_str_isnum(argv[i + 1]))
            my_puterr("Invalid nbr_cycle, parameter must be an number");
        i += 2;
    }
    while (argv[i] != NULL) {
        if (number_error(argv, &i))
            return 1;
        if (adress_error(argv, &i))
            return 1;
        if (file_error(argv, &i))
            return 1;
    }
    return 0;
}

static int check_multiple(int *id, size_t size, size_t i)
{
    for (size_t j = i + 1; j < size; j++) {
        if (id[i] == id[j])
            return 1;
    }
    return 0;
}

static int invalid_id(char **argv)
{
    int *id;
    int size = 0;
    size_t j = 0;

    for (size_t i = 1; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "-n") == 0)
            size++;
    }
    id = malloc(sizeof(int) * size);
    for (size_t i = 1; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "-n") == 0) {
            id[j] = my_atoi(argv[i + 1]);
            j++;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        if (check_multiple(id, size, i))
            return 1;
    }
    return 0;
}

int error(int ac, char **av)
{
    if (ac < 2) {
        my_puterr("Not enough arguments, try again with -h\n");
        return 1;
    }
    if (wrong_number_heros(av) || invalid_arg(av) || invalid_id(av)) {
        return 1;
    }
    return 0;
}
