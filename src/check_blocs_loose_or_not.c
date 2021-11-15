/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** check_blocs
*/

#include "my.h"
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_coin(char *map, int remaining, int move_1, int move_2)
{
    if ((map[move_1] == '#' || map[move_1] == 'X') &&
    (map[move_2] == '#' || map[move_2] == 'X')) {
        remaining--;
        return (remaining);
    } else {
        return (remaining);
    }
}

int check_move(char *map, int pos_box, int remaining, char *comp_map)
{
    int move_sup = (count_col(map) + 1) * -1 + pos_box;
    int move_inf = count_col(map) + 1 + pos_box;
    int move_left = -1 + pos_box;
    int move_right = 1 + pos_box;

    remaining = check_coin(map, remaining, move_sup, move_left);
    remaining = check_coin(map, remaining, move_sup, move_right);
    remaining = check_coin(map, remaining, move_inf, move_left);
    remaining = check_coin(map, remaining, move_inf, move_right);
    return (remaining);
}

int check_loose(char *map, int blocs, char **av)
{
    int i = 0;
    int remaining = blocs;
    int pos_box = 0;
    char *comp_map = c_map(av);

    while (map[i] != '\0') {
        if (map[i] == 'X') {
            pos_box = i;
            remaining = check_move(map, pos_box, remaining, comp_map);
            blocs--;
        }
        i++;
    }
    if (remaining == 0) {
        loose(blocs);
    }
}

int nb_blocs(char *map, int blocs, char **av)
{
    mvprintw(0, 0, "Nb of moving boxes = %d", blocs);
    if (blocs == 0)
        final_win(blocs);
    else
        check_loose(map, blocs, av);
    return (blocs);
}
