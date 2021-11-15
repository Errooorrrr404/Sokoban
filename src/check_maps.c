/*
** EPITECH PROJECT, 2018
** bootstrap_my_popup
** File description:
** check_map
*/

#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int check_size(char *map, int i, int count)
{
    int size = count_col(map);

    if (size != count)
    exit (ERROR);
    else
    count = 0;
    return (count);
}

void check_box_map2(char *map)
{
    int size_line = count_col(map);
    int size_col = count_line(map);
    int i = 0;

    while (i != size_line) {
        if (map[i] == '#')
        i++;
        else
        exit (ERROR);
    }
    i = size_line * size_col + size_line;
    while (map[i] != '\0') {
        if (map[i] == '#')
        i++;
        else {
            exit (ERROR);
        }
    }
}

void check_box_map(char *map)
{
    int size = count_col(map) - 1;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '#' && map[size] == '#') {
            i += count_col(map) + 1;
            size += count_col(map) + 1;
        } else {
            exit (ERROR);
        }
    }
    check_box_map2(map);
}

int check_map2(char *map, char **av)
{
    int p = 0;
    int i = 0;
    int count = 0;

    while (map[i] != '\0') {
        if (map[i] == 'P')
        p++;
        if (map[i] == '\n')
        count = check_size(map, i, count);
        else
        count++;
        i++;
    }
    if (p != 1)
    exit (ERROR);
    check_box_map(map);
    ini_map(map, av);
}

int check_map(char *map, char **av)
{
    int i = 0;
    int x = 0;
    int blocs = 0;

    while (map[i] != '\0') {
        if (map[i] == 'X')
        x++;
        else if (map[i] == 'O')
        blocs++;
        if (map[i] == '#' || map[i] == ' ' || map[i] == 'P' ||
        map[i] == '\n' || map[i] == 'O' || map[i] == 'X')
        i++;
        else
        exit (ERROR);
    }
    if (blocs != x)
    exit (ERROR);
    check_map2(map, av);
}
