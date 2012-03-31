CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
SOURCES=game.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
