CC = gcc

CFLAGS = -Wall -Wextra

SRC = main.c cell.c

OBJS = $(SRC:.c=.o)

NAME = diary

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf $(OBJS)

clean:
	rm -f $(NAME)
	rm -rf $(OBJS)
	rm -rf a.out

re: clean all

.PHONY: all clean re