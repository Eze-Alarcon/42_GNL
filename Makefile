CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SOURCES =	get_next_line.c \
			get_next_line_utils.c

OBJS_FILES	= $(SOURCES:.c=.o)

NAME = gnl.a

HEADER = get_next_line.h

TEST_FILE = test.out

$(NAME):	$(OBJS_FILES)
	ar rcs $(NAME) $(OBJS_FILES)

all: $(NAME)

clean:
	$(RM) $(OBJS_FILES)
	$(RM) $(TEST_FILE)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

test: all
	clear
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST_FILE)
	./$(TEST_FILE)

norm:
	clear
	norminette $(SOURCES) $(HEADER) -R CheckForbiddenSourceHeader

.PHONY:	all clean fclean re test norm
