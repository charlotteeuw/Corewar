/*
** EPITECH PROJECT, 2024
** Lib
** File description:
** my_memcpy.c
*/

#include <lib.h>

void *my_memcpy(void *dest, void *src, size_t n)
{
    size_t i = 0;
    char *dest_bytes = dest;
    char *src_bytes = src;

    while (i < n) {
        dest_bytes[i] = src_bytes[i];
        i++;
    }
    return dest;
}
