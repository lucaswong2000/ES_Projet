
all: LRU.c aging.c main.c
	gcc aging.c LRU.c main.c -o main
