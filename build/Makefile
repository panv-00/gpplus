CPP=g++
PKGS=sdl2 SDL2_gfx
CFLAGS=-Wall -O3 -g -ggdb -pedantic `pkg-config --cflags $(PKGS)`
LIBS=`pkg-config --libs $(PKGS)` -lm
VPATH=../src

OBJECTS= \
	Gui.o \
	BrainCell.o \
	Brain.o \
	Agent.o \
	Game.o \
	Food.o \
	Wall.o \

DEPLIST= \
	definitions.h

default: $(OBJECTS)
	$(CPP) -o ../gpplus ../src/gpplus.cpp \
		$(OBJECTS) \
		$(CFLAGS) \
		$(LIBS)

%.o: %.cpp %.h $(DEPLIST)
	$(CPP) -c $< -o $*.o $(CFLAGS) $(LIBS)
