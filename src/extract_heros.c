/*
** EPITECH PROJECT, 2024
** extract_heros.c
** File description:
** extract_heros.c
*/

#include <corewar.h>

int count_heros(char **argv)
{
    int count = 0;
    size_t i = 1;

    if (my_strcmp(argv[1], "-dump") == 0) {
        i += 2;
    }
    while (argv[i]) {
        if (my_strcmp(argv[i], "-n") == 0 || my_strcmp(argv[i], "-a") == 0) {
            i += 2;
            continue;
        }
        count++;
        i++;
    }
    return count;
}

void *reverse(void *ptr, size_t size)
{
    char *bytes = ptr;
    char tmp;

    for (size_t i = 0; i < size / 2; i++) {
        tmp = bytes[i];
        bytes[i] = bytes[size - i - 1];
        bytes[size - i - 1] = tmp;
    }
    return ptr;
}

static void get_number(char **argv, size_t *i, int *number)
{
    static int id = 0;

    if (my_strcmp(argv[*i], "-n") == 0) {
        *number = my_atoi(argv[*i + 1]);
        *i += 2;
        id = *number + 1;
    } else {
        *number = id;
        id++;
    }
}

static void get_adress(char **argv, int nb_heros, size_t *i, int *adress)
{
    static int pos = 0;

    if (my_strcmp(argv[*i], "-a") == 0) {
        *adress = my_atoi(argv[*i + 1]) % MEM_SIZE;
        *i += 2;
    } else {
        *adress = pos;
    }
    pos += MEM_SIZE / nb_heros;
}

static void open_file(char *prog_name, hero_t *hero)
{
    char *buffer;
    struct stat sb;
    int src = open(prog_name, O_RDONLY);
    header_t header;

    stat(prog_name, &sb);
    buffer = malloc(sizeof(char) * sb.st_size);
    read(src, buffer, sb.st_size);
    my_memcpy(&header, buffer, sizeof(header_t));
    hero->cycle_to_die = CYCLE_TO_DIE;
    hero->name = my_strdup(header.prog_name);
    hero->prog_size = header.prog_size;
    reverse(&hero->prog_size, 4);
    hero->prog = malloc(hero->prog_size);
    my_memcpy(hero->prog, buffer + sizeof(header_t),
        MY_MIN(hero->prog_size, sb.st_size - sizeof(header_t)));
    close(src);
    free(buffer);
}

hero_t **get_heros(char **argv, int nb_heros)
{
    hero_t **heros = malloc(sizeof(hero_t *) * (nb_heros + 1));
    size_t i = 1;
    size_t j = 0;

    heros[nb_heros] = NULL;
    if (my_strcmp(argv[1], "-dump") == 0)
        i += 2;
    while (argv[i]) {
        heros[j] = malloc(sizeof(hero_t));
        get_number(argv, &i, &heros[j]->nb);
        get_adress(argv, nb_heros, &i, &heros[j]->adress);
        open_file(argv[i], heros[j]);
        i++;
        j++;
    }
    return heros;
}
