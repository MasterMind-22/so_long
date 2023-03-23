# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 14:14:12 by yonadry           #+#    #+#              #
#    Updated: 2023/03/23 16:54:08 by yonadry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus

LIB = so_long.a
LIB_BONUS = so_long_bonus.a
SRCS =	\
		./mandatory/map_reader.c \
		./mandatory/map_check_tools.c \
		./mandatory/other_functions.c \
		./mandatory/check_all.c \
		./mandatory/backtracking.c \
		./mandatory/fill_structs.c \
		./mandatory/move_player.c \
		./mandatory/get_next_line.c \
		./mandatory/get_next_line_utils.c \
		./mandatory/itoa.c \
		./mandatory/so_long.c \

BONUS_SRCS =	\
		./mandatory/map_reader.c \
		./mandatory/map_check_tools.c \
		./mandatory/other_functions.c \
		./mandatory/check_all.c \
		./mandatory/backtracking.c \
		./mandatory/itoa.c \
		./bonus/fill_structs_bonus.c \
		./bonus/move_player_bonus.c \
		./mandatory/get_next_line.c \
		./mandatory/get_next_line_utils.c \
		./bonus/animation.c \
		./bonus/player_animation.c \
		./bonus/enemy_bonus.c \
		./bonus/so_long_bonus.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RESOURCES = get_next_line.a
DATE = $(shell date)

all :  $(NAME)

bonus :  $(BONUS_NAME)

%.o : %.c so_long.h so_long_bonus.h
	@ $(CC) $(CFLAGS) -Imlx -c $<

$(LIB) : $(OBJS)
	@ ar -r $@ $?

$(LIB_BONUS) : $(BONUS_OBJS)
	@ ar -r $@ $?


$(NAME) : $(LIB)
	@ $(CC) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#	$(CC) so_long.c $(LIB) libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -o $(NAME)

$(BONUS_NAME) : $(LIB_BONUS)
	@ $(CC) $(LIB_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)
#	$(CC) so_long_bonus.c $(LIB_BONUS) libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS_NAME)

clean :
	@ rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@ rm -f  $(LIB) $(NAME) $(BONUS_NAME) $(LIB_BONUS)

re : fclean all

push:
	@git add .
	@git commit -m "$(DATE)"
	@git push

.PHONY : all clean fclean re