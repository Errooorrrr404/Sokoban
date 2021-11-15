/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** init_map
*/

#include "my.h"
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *ini_map(char *map, char **av)
{
    int pos_player = check_pos_player(map, pos_player);
    int lign = 0;
    int blocs = 0;
    int x_max;
    int y_max;

    initscr();
    getmaxyx(stdscr, y_max, x_max);
    check_size_map(map, x_max, y_max, av);
    curs_set(FALSE);
    noecho();
    clear();
    display_map(map, lign);
    keypad(stdscr, TRUE);
    key_event_map(map, pos_player, lign, av);
    endwin();
}
