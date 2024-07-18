CC=gcc
CFLAGS=-g -Wall -std=c99
TARGETS=hex shapes coin
all: $(TARGETS)
hex: hex.c
	$(CC) $(CFLAGS) -o $@ $@.c
shapes: shapes.c
	$(CC) $(CFLAGS) -o $@ $@.c
coin: coin.c
	$(CC) $(CFLAGS) -o $@ $@.c
clean:
	rm -rf *.o *~ $(TARGETS)


