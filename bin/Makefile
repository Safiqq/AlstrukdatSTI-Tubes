ADT = ../src/ADT/array/array.c ../src/ADT/arrayOfChar/array.c ../src/ADT/map/map.c ../src/ADT/matriks/matriks.c ../src/ADT/mesinkarakter/mesinkarakter.c ../src/ADT/mesinkata/mesinkata.c ../src/ADT/queue/queue.c ../src/ADT/queueDS/queue.c ../src/ADT/stackTOH/stack.c ../src/ADT/stackH/stack.c

PROGRAMS = $(wildcard ../src/*.c)

all: bnmo

bnmo: $(ADT) $(PROGRAMS)
	gcc -std=gnu90 -o bnmo $(ADT) $(PROGRAMS) -I.
