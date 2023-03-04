NAME = so_long
LIB = so_long.a
SRCS =	map_reader.c \
		map_check_tools.c \
		other_functions.c \
		check_all.c \
		backtracking.c \
		fill_structs.c \
		move_player.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o) \
		get_next_line.o \
		get_next_line_utils.o \

CC = cc
CFLAGS = -Wall -Wextra -Werror
RESOURCES = get_next_line.a
DATE = $(shell date --iso=date)

all :  $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $<

$(LIB) : $(OBJS)
	@ cd ./get_next_line && make
	@ ar -r $@ $?


$(NAME) : $(LIB)
	$(CC) so_long.c $(LIB)  ./mlx_linux/libmlx.a -Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@ rm -f $(OBJS)

fclean : clean
	@ rm -f  $(LIB) $(NAME) get_next_line.a
	@ cd ./get_next_line && make fclean

re : fclean all

push:
	@git add .
	@git commit -m "$(DATE)"
	@git push

.PHONY : all clean fclean re