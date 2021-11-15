/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** putchar
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}
