EXECUTABLE = main
COMPILE = gcc
all:$(EXECUTABLE)
total: clear $(EXECUTABLE) run
clear:
	$(RM) *.o $(EXECUTABLE)
$(EXECUTABLE): main.o LRU.o linkLRU.o random.o
	$(COMPILE) main.o LRU.o linkLRU.o random.o -o $(EXECUTABLE) 
main.o: main.c
	$(COMPILE) -c main.c
LRU.o: LRU.h LRU.c
	$(COMPILE) -c LRU.c
linkLRU.o: linkLRU.h linkLRU.c
	$(COMPILE) -c linkLRU.c
random.o: random.c random.h
	$(COMPILE) -c random.c
run:
	./$(EXECUTABLE)
