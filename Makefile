CC=gcc
HEADER=tictak.h funcs.h

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $<

tictac: tictac.o funcs.o
	$(CC) -o tictac tictac.o funcs.o

clean:
	rm funcs.o tictac.o

install:
	cp tictac ~/.local/bin/