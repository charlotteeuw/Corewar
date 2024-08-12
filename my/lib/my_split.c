/*
** EPITECH PROJECT, 2024
** split
** File description:
** my_split.c
*/

#include <lib.h>
#include <op.h>

int my_count_words(char *str)
{
    int count = 0;
    int index = 0;

    while (str[index] != '\0') {
        while (str[index] == ' ' || str[index] == '\t'
        || str[index] == '\n' || str[index] == ',')
            index++;
        if (str[index] != '\0')
            count++;
        while (str[index] != ' ' && str[index] != '\t'
            && str[index] != ',' &&
            str[index] != '\n' && str[index] != '\0')
            index++;
    }
    return count;
}

int get_beg(char *str, int end, int *quote)
{
    int beg = end;
    int comment = 0;

    for (; str[beg]; beg++) {
        if (str[beg] == COMMENT_CHAR)
            comment = 1;
        if (str[beg] == '\n')
            comment = 0;
        if (comment == 0 &&
            str[beg] != ' ' &&
            str[beg] != '\t' &&
            str[beg] != '\n' &&
            str[beg] != SEPARATOR_CHAR)
            break;
    }
    if (str[beg] == '"') {
        *quote = 1;
        beg++;
    }
    return beg;
}

int get_end(char *str, int beg, int *quote)
{
    int end = beg;

    if (*quote) {
        while (str[end] != '"' && str[end] != '\0')
            end++;
        if (str[end] != '"') {
            my_puterr("Unmatched quote\n");
            return -1;
        }
    } else
        while (str[end] != ' ' && str[end] != '\t'
            && str[end] != SEPARATOR_CHAR
            && str[end] != COMMENT_CHAR
            && str[end] != '\n'
            && str[end] != '\0')
            end++;
    return end;
}

char **my_split(char *str)
{
    char **tab = malloc(sizeof(char *) * (my_count_words(str) + 1));
    int beg = 0;
    int end = 0;
    int quote = 0;
    int index = 0;

    for (; str[end] != '\0'; index++) {
        beg = get_beg(str, end, &quote);
        if (str[beg] == '\0')
            break;
        end = get_end(str, beg, &quote);
        tab[index] = malloc(sizeof(char) * (end - beg + 1));
        my_strncpy(tab[index], &str[beg], end - beg);
        if (quote) {
            end++;
            quote = 0;
        }
    }
    tab[index] = NULL;
    return tab;
}
