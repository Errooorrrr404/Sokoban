##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/check_blocs_loose_or_not.c \
	  ./src/check_maps.c \
	  ./src/count_col.c \
	  ./src/count_line.c \
	  ./src/init_map.c \
	  ./src/map.c \
	  ./src/moove.c \
	  ./src/my_putchar.c \
	  ./src/my_putstr.c \
	  ./src/my_strlen.c \
	  ./src/win_loose.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
