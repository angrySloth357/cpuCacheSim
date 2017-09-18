CC=g++

CFLAGS= -std=c++11 -o main
SOURCES= *.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=main

all:

	$(CC) $(CFLAGS) $(SOURCES) $(SDL2) -D_FILE_OFFSET_BITS=64

clean:

	rm main
