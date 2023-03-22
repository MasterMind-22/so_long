# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 14:14:12 by yonadry           #+#    #+#              #
#    Updated: 2023/03/22 20:36:44 by yonadry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		itoa.c \

BONUS_SRCS =	\
		map_reader.c \
		map_check_tools.c \
		other_functions.c \
		check_all.c \
		backtracking.c \
		itoa.c \
		fill_structs_bonus.c \
		move_player_bonus.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		animation.c \
		so_long_bonus.c \

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

%.o : %.c so_long.h so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $<

$(LIB) : $(OBJS)
	@ cd ./get_next_line && make
	@ ar -r $@ $?

$(LIB_BONUS) : $(BONUS_OBJS)
	@ cd ./get_next_line && make
	@ ar -r $@ $?


$(NAME) : $(LIB)
	$(CC) so_long.c $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#	$(CC) so_long.c $(LIB) libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

$(BONUS_NAME) : $(LIB_BONUS)
	 $(CC) $(LIB_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)
#	$(CC) so_long_bonus.c $(LIB_BONUS) libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS_NAME)

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