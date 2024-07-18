CC := gcc
CFLAGS := -g -Wall -std=c99
OFILES =  linkedlist-main.o linkedlist.o
TARGETS :=  linkedlist-main

all: $(TARGETS)

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) -c $(CFLAGS) $<

linkedlist-main.o : linkedlist-main.c
	$(CC) -c $(CFLAGS) $<
linkedlist-main: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

clean:
	rm -rf *.o $(TARGETS)
