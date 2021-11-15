/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Task03 Day04
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int count_line(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            j++;
        }
        i++;
    }
    return (j);
}
