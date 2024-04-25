####--COMP--##############################

CC		= gcc
CFLAGS		= -Wall -Werror -Wextra


####--OUTPUT--############################

NAME		= exec.a
INCLUDE		= push_swap.h


####--MACRO--#############################

RM	= rm -f
AR	= ar -rcs


####--INPUT--#############################

SOURCES =	push_swap.c utils.c split.c sort_stack.c main.c\
		init.c node_init.c node_init_part_2.c stack_utils.c\
		errors.c free_utils.c\
		push_move.c rev_rotate_move.c rotate_move.c swap_move.c \

OBJECTS = $(SOURCE:.c=.o)

####--RULES--#############################

all: $(NAME)
%.o: %.c
	${CC} ${CFLAGS} -c -o $< $@

${NAME}: ${OBJETS} ${INCLUDE}
	${AR} ${NAME} ${OBJETS}

clean:
	${RM} ${OBJECTS}

fclean:
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
