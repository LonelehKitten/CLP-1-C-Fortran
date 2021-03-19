ifeq ($(OS), Windows_NT)
TARGET=program.exe
else
TARGET=program
endif

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
CC=g++

all: $(TARGET) clear

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) -c $< -o $@

ifeq ($(OS), Windows_NT)
clear:
	-@del /f /a *.o
else
clear:
	-@rm -rvf *.o
endif