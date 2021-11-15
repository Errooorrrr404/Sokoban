/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** win_loose
*/

#include "my.h"
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void final_win(int blocs)
{
    char *str = "YYYEEEEEEAAAAHHHHHHH !";
    int size = my_strlen(str);

    clear();
    refresh();
    mvprintw(LINES/2, COLS/2 - (size / 2), str);
    while (1) {
        if (getch() == ' ') {
            clear();
            refresh();
            endwin();
            exit (WIN);
        }
    }
}

void loose(int blocs)
{
    char *str = "OH NO, YOU LOOSE !";
    int size = my_strlen(str);

    clear();
    refresh();
    mvprintw(LINES/2, COLS/2 - (size / 2), str);
    while (1) {
        if (getch() == ' ') {
            clear();
            refresh();
            endwin();
            exit (LOOSE);
        }
    }
}
