CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -Iinclude
LIBS = `pkg-config --libs gtk+-3.0`
SRC = src/kernel.c src/memory.c src/process.c src/io.c src/gui.c main.c
OBJ = $(SRC:.c=.o)
EXEC = ai_os

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)