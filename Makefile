NAME = so_long
BONUS_NAME = so_long_bonus

LIB = so_long.a
LIB_BONUS = so_long_bonus.a
SRCS =	\
		map_reader.c \
		map_check_tools.c \
		other_functions.c \
		check_all.c \
		backtracking.c \
		fill_structs.c \
		move_player.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \

BONUS_SRCS =	\
<<<<<<< HEAD
		map_reader.c \
		map_check_tools.c \
		other_functions.c \
		check_all.c \
		backtracking.c \
		fill_structs_bonus.c \
		move_player_bonus.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
=======
				map_reader.c \
				map_check_tools.c \
				other_functions.c \
				check_all.c \
				backtracking.c \
				./so_long_bonus/fill_structs_bonus.c \
				./so_long_bonus/move_player_bonus.c \
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
>>>>>>> 8db0a2ad4484516ddf7317c8eaac23254dd62965

OBJS = $(SRCS:.c=.o) \
		get_next_line.o \
		get_next_line_utils.o \

BONUS_OBJS = $(BONUS_SRCS:.c=.o) \
		get_next_line.o \
		get_next_line_utils.o \

CC = cc
CFLAGS = -Wall -Wextra -Werror
RESOURCES = get_next_line.a
DATE = $(shell date)

all :  $(NAME)

bonus :  $(BONUS_NAME)

<<<<<<< HEAD
%.o : %.c so_long.h so_long_bonus.h
=======
%.o : %.c so_long.h
>>>>>>> 8db0a2ad4484516ddf7317c8eaac23254dd62965
	$(CC) $(CFLAGS) -Imlx -c $<

$(LIB) : $(OBJS)
	@ cd ./get_next_line && make
	@ ar -r $@ $?

$(LIB_BONUS) : $(BONUS_OBJS)
	@ cd ./get_next_line && make
	@ ar -r $@ $?


$(NAME) : $(LIB)
<<<<<<< HEAD
	$(CC) so_long.c $(LIB) libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(BONUS_NAME) : $(LIB_BONUS)
	$(CC) so_long_bonus.c $(LIB_BONUS) libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS_NAME)
# $(CC) ./so_long_bonus/so_long_bonus.c $(LIB_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)
=======
	$(CC) so_long.c $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS_NAME) : $(LIB_BONUS)
	$(CC) ./so_long_bonus/so_long_bonus.c $(LIB_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)
>>>>>>> 8db0a2ad4484516ddf7317c8eaac23254dd62965

clean :
	@ rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@ rm -f  $(LIB) $(NAME) $(BONUS_NAME) $(LIB_BONUS) get_next_line.a
	@ cd ./get_next_line && make fclean

re : fclean all

push:
	@git add .
	@git commit -m "$(DATE)"
	@git push

.PHONY : all clean fclean re