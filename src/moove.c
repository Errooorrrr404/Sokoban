/*
** EPITECH PROJECT, 2018
** bootstrap_my_popup
** File description:
** moove
*/

#include "my.h"
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *special_moove(int pos_player, char *map, int moove, int lign)
{
    if (map[pos_player + moove] == ' ') {
        map[pos_player + moove] = map[pos_player];
        map[pos_player] = ' ';
    } else if (map[pos_player + moove] == '#')
        return (map);
    if (map[pos_player + moove] == 'X') {
        if (map[pos_player + (2 * moove)] == ' ') {
            map[pos_player + (2 * moove)] = 'X';
            map[pos_player + moove] = map[pos_player];
            map[pos_player] = ' ';
        }
        if (map[pos_player + (2 * moove)] == 'O') {
            map[pos_player + (2 * moove)] = 'X';
            map[pos_player + moove] = map[pos_player];
            map[pos_player] = ' ';
        }
    }
    return (map);
}

int event_key_left(int pos_player, char *map, int lign, char **av)
{
    int moove = 1 * -1;

    pos_player = check_pos_player(map, pos_player);
    map = special_moove(pos_player, map, moove, lign);
    ini_map(map, av);
    return (pos_player);
}

int event_key_right(int pos_player, char *map, int lign, char **av)
{
    int moove = 1;

    pos_player = check_pos_player(map, pos_player);
    map = special_moove(pos_player, map, moove, lign);
    ini_map(map, av);
    return (pos_player);
}

int event_key_up(int pos_player, char *map, int lign, char **av)
{
    int moove = (count_col(map) + 1) * -1;

    pos_player = check_pos_player(map, pos_player);
    map = special_moove(pos_player, map, moove, lign);
    ini_map(map, av);
    return (pos_player);
}

int event_key_down(int pos_player, char *map, int lign, char **av)
{
    int moove = count_col(map) + 1;

    pos_player = check_pos_player(map, pos_player);
    map = special_moove(pos_player, map, moove, lign);
    ini_map(map, av);
    return (pos_player);
}
