CC=gcc
CFLAGS= -g -Wall -Wextra -Werror -D BUFFER_SIZE=1
DEPS = get_next_line.h
OBJ = get_next_line_utils.o get_next_line.o prova.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

getnextmake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o getnextmake 

