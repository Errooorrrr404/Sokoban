/*
** EPITECH PROJECT, 2018
** bootstrap_my_popup
** File description:
** test
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

void h_flag(void)
{
    my_putstr("USAGE\n");
    my_putstr("      ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("      map  file representing the warehouse map, containing '#'");
    my_putstr(" for walls, \n");
    my_putstr("           'P' for the player, 'X' for boxes and 'O' for");
    my_putstr(" storage locations.\n");
}

char *c_map(char **av)
{
    int fd;
    char *str = malloc(sizeof(char) * (BUFFER));
    char *map = malloc(sizeof(char) * (BUFFER));
    int i = 0;

    fd = open(av[1], O_RDONLY);
    read(fd, str, BUFFER);
    while (str[i] != '\0') {
        map[i] = str[i];
        i++;
    }
    map[i] = '\0';
    free(str);
    return (map);
    close(fd);
}

void f_map(char **av)
{
    int fd;
    char *str = malloc(sizeof(char) * (BUFFER));
    char *map = malloc(sizeof(char) * (BUFFER));
    int i = 0;

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    exit (ERROR);
    read(fd, str, BUFFER);
    while (str[i] != '\0') {
        map[i] = str[i];
        i++;
    }
    map[i] = '\0';
    free(str);
    check_map(map, av);
    close(fd);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
            h_flag();
            return (0);
        } else
        f_map(av);
    } else if (ac > 2 || ac == 1)
    exit (ERROR);
}
