/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** putstr
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
}
