/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** usage.c
*/

#include <corewar.h>

int usage(char *param)
{
    struct stat sb;
    int fd;
    char *buff;

    if (my_strcmp(param, "-h") == 0 || my_strcmp(param, "--help") == 0) {
        stat("readme", &sb);
        buff = malloc(sizeof(char) * (sb.st_size + 1));
        fd = open("readme", O_RDONLY);
        read(fd, buff, sb.st_size + 1);
        write(1, buff, sb.st_size + 1);
        close(fd);
        return 1;
    }
    return 0;
}
