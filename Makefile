EXECUTABLE = main
COMPILE = gcc
all:$(EXECUTABLE)
total: clear $(EXECUTABLE) run
clear:
	$(RM) *.o $(EXECUTABLE)
$(EXECUTABLE): main.o LRU.o linkLRU.o random.o aging.o fifo.o
	$(COMPILE) -Wall -g main.o LRU.o linkLRU.o random.o aging.o fifo.o -o $(EXECUTABLE) 
main.o: main.c
	$(COMPILE) -c main.c
LRU.o: LRU.h LRU.c
	$(COMPILE) -c LRU.c
linkLRU.o: linkLRU.h linkLRU.c
	$(COMPILE) -c linkLRU.c
aging.o: aging.c aging.h
	$(COMPILE) -c aging.c
random.o: random.c random.h
	$(COMPILE) -c random.c
fifo.o: fifo.h fifo.c
	$(COMPILE) -c fifo.c
run:
	./$(EXECUTABLE)
