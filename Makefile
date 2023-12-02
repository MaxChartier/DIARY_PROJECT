CC = gcc

CFLAGS = -Wall -Wextra

SRC2 = main2.c cell.c complementary.c timer.c

SRC3 = main3.c cell.c complementary.c timer.c

OBJS2 = $(SRC2:.c=.o)

OBJS3 = $(SRC3:.c=.o)

NAME2 = diary2

NAME3 = diary3

all: $(NAME3)

diary2: $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf $(OBJS2)

diary3: $(OBJS3)
	$(CC) $(CFLAGS) $^ -o $@
	rm -rf $(OBJS3)

clean:
	rm -f $(NAME2) $(NAME3)
	rm -rf $(OBJS2)
	rm -rf $(OBJS3)
	rm -rf a.out

re: clean all

.PHONY: all clean re
