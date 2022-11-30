STD_VER := c99

ADTArray := arrayChar arrayMap arrayStr
ADTList := listDP
ADTMap := mapInt mapStr
ADTMatrix := matrixInt
ADTMesin := mesinkarakter mesinkata
ADTQueue := queueDS queueInt
ADTStack := stackInt stackStr
ADT := $(ADTArray) $(ADTList) $(ADTMap) $(ADTMatrix) $(ADTMesin) $(ADTQueue) $(ADTStack)

ADT := ${foreach var,${ADT},../src/ADT/$(var)/$(var).c}

GAME := $(wildcard ../src/game/*.c)

COMMAND := $(wildcard ../src/command/*.c)

BNMO := ../src/lib.c $(ADT) $(GAME) $(COMMAND)

all: bnmo

bnmo:
	gcc -std=$(STD_VER) -o bnmo $(BNMO) -I.
