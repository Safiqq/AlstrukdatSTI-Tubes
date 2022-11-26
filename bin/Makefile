ADTArray = ../src/ADT/arrayChar/arrayChar.c ../src/ADT/arrayMap/arrayMap.c ../src/ADT/arrayStr/arrayStr.c
ADTList = ../src/ADT/listDP/listDP.c
ADTMap = ../src/ADT/mapInt/mapInt.c ../src/ADT/mapStr/mapStr.c
ADTMatriks = ../src/ADT/matriksChar/matriksChar.c
ADTMesin = ../src/ADT/mesinkarakter/mesinkarakter.c ../src/ADT/mesinkata/mesinkata.c
ADTQueue = ../src/ADT/queueDS/queueDS.c ../src/ADT/queueInt/queueInt.c
ADTStack = ../src/ADT/stackInt/stackInt.c ../src/ADT/stackStr/stackStr.c

ADT = $(ADTArray) $(ADTList) $(ADTMap) $(ADTMatriks) $(ADTMesin) $(ADTQueue) $(ADTStack)

GAME = $(wildcard ../src/game/*.c)

COMMAND = $(wildcard ../src/command/*.c)

all: bnmo

bnmo: $(ADT) $(GAME) $(COMMAND)
	gcc -std=c99 -o bnmo ../src/lib.c $(ADT) $(GAME) $(COMMAND) -I.
