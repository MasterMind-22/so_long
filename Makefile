NAME = so_long.a
SRCS =	map_reader.c \
		map_check_tools.c \
		other_functions.c \
		check_all.c \

OBJS = $(SRCS:.c=.o) \
		./get_next_line/get_next_line.o \
		./get_next_line/get_next_line_utils.o \

CC = cc
CFLAGS = -Wall -Wextra -Werror
RESOURCES = get_next_line.a


all :  $(RESOURCES) $(NAME)

$(RESOURCES) :
	@ cd ./get_next_line && make

$(NAME) : $(OBJS)
	@ ar -r $@ $?
	@ rm -f get_next_line.a

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $<

clean :
	@ rm -f *.o*

fclean : clean
	@ rm -f  $(NAME) get_next_line.a
	@ cd ./get_next_line && make fclean

re : fclean all

.PHONY : all clean fclean re