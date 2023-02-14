NAME = get_next_line.a
SRCS =	get_next_line.c \
		get_next_line_utils.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ ar -r $@ $? && cp get_next_line.a ../

%.o : %.c get_next_line.h
	@ $(CC) $(CFLAGS) -c $<

clean :
	@ rm -f $(OBJ)

fclean : 
	@ rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all clean fclean re