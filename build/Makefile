CPP=g++
CFLAGS=-Wall -O3 -g
VPATH=../src

OBJECTS= \
	Gui.o \
	BrainCell.o \
	Brain.o \
	Agent.o \
	Game.o \
	Food.o \

default: $(OBJECTS)
	$(CPP) -o ../gpplus ../src/gpplus.cpp \
		$(OBJECTS) \
		$(CFLAGS)

%.o: %.cpp %.h
	$(CPP) -c $< -o $*.o $(CFLAGS)
