/*
** EPITECH PROJECT, 2018
** bootstrap_my_popup
** File description:
** map
*/

#include "my.h"
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int check_blocs(char *map, int blocs)
{
    int i = 0;

    blocs = 0;
    while (map[i] != '\0') {
        if (map[i] == 'O')
        blocs++;
        i++;
    }
    return (blocs);
}

char *display_map(char *map, int lign)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (count_col(map) + 1));
    int middle = count_line(map);
    int size = count_col(map);

    while (map[i] != '\0') {
        j = 0;
        while (j != size) {
            str[j] = map[i];
            i++;
            j++;
        }
        str[j] = '\0';
        i++;
        mvaddstr(LINES/2 - (middle / 2) + lign, (COLS/2) - (size / 2), str);
        lign++;
        refresh();
    }
    free(str);
    return (map);
}

int check_pos_player(char *map, int pos_player)
{
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == 'P') {
            pos_player = i;
            return (pos_player);
        } else
            i++;
    }
}

void key_event_map(char *map, int pos_player, int lign, char **av)
{
    int blocs = check_blocs(map, blocs);

    nb_blocs(map, blocs, av);
    while (1) {
        switch (getch()) {
            case KEY_LEFT:
            pos_player = event_key_left(pos_player, map, lign, av);
            case KEY_RIGHT:
            pos_player = event_key_right(pos_player, map, lign, av);
            case KEY_UP:
            pos_player = event_key_up(pos_player, map, lign, av);
            case KEY_DOWN:
            pos_player = event_key_down(pos_player, map, lign, av);
            case ' ':
            f_map(av);
        }
    }
}

char *check_size_map(char *map, int x_max, int y_max, char **av)
{
    if (x_max < count_col(map) || y_max < count_line(map) + 1) {
        clear();
        refresh();
        endwin();
        my_putstr("PLEASE INCREASE THE SIZE OF YOUR TERMINAL\n");
        exit (ERROR);
    }
}
