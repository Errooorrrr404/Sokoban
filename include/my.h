/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Task02 Day09
*/

#ifndef MY_H_
#define MY_H_
#define BUFFER 30000
#define ERROR 84
#define WIN 0
#define LOOSE 1

int check_coin(char *map, int remaining, int move_1, int move_2);
int check_move(char *map, int pos_box, int remaining, char *comp_map);
int check_loose(char *map, int blocs, char **av);
int nb_blocs(char *map, int blocs, char **av);
char *check_size_map(char *map, int x_max, int y_max, char **av);
char *ini_map(char *map, char **av);
int check_size(char *map, int i, int count);
void check_box_map2(char *map);
void check_box_map(char *map);
int check_map2(char *map, char **av);
int check_map(char *map, char **av);
int count_line(char *str);
int count_col(char *str);
int check_blocs(char *map, int blocs);
char *display_map(char *map, int lign);
int check_pos_player(char *map, int pos_player);
void key_event_map(char *map, int pos_player, int lign, char **av);
char *special_moove(int pos_player, char *map, int moove, int lign);
int event_key_left(int pos_player, char *map, int lign, char **av);
int event_key_right(int pos_player, char *map, int lign, char **av);
int event_key_up(int pos_player, char *map, int lign, char **av);
int event_key_down(int pos_player, char *map, int lign, char **av);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void event_2(int blocs);
void final_win(int blocs);
void loose(int blocs);
void f_map(char **av);
char *c_map(char **av);

#endif
