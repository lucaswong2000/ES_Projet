EXECUTABLE = main
COMPILE = gcc
all:$(EXECUTABLE)
total: clear $(EXECUTABLE) run
clear:
	$(RM) *.o $(EXECUTABLE)
<<<<<<< HEAD
$(EXECUTABLE): main.o LRU.o linkLRU.o aging.o
	$(COMPILE) -Wall main.o LRU.o linkLRU.o aging.o -o $(EXECUTABLE) 
=======
$(EXECUTABLE): main.o LRU.o linkLRU.o random.o
	$(COMPILE) main.o LRU.o linkLRU.o random.o -o $(EXECUTABLE) 
>>>>>>> random
main.o: main.c
	$(COMPILE) -c main.c
LRU.o: LRU.h LRU.c
	$(COMPILE) -c LRU.c
linkLRU.o: linkLRU.h linkLRU.c
	$(COMPILE) -c linkLRU.c
<<<<<<< HEAD
aging.o: aging.c aging.h
=======
random.o: random.c random.h
	$(COMPILE) -c random.c
>>>>>>> random
run:
	./$(EXECUTABLE)
