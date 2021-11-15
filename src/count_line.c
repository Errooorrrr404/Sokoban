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

int count_col(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return (i);
}
