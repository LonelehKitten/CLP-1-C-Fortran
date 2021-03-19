ifeq ($(OS), Windows_NT)
TARGET=program.exe
else
TARGET=program
endif

LIBPATH=lib
OBJPATH=obj
MAIN=main.c

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CC=gcc

all: $(TARGET) clear

$(TARGET): $(OBJ)
	$(CC) $(MAIN) $(OBJPATH)/$^ -o $@

%.o: %.c
	$(CC) -c $(LIBPATH)/$< -o $(OBJPATH)/$@

ifeq ($(OS), Windows_NT)
clear:
	-@del /f /a *.o
else
clear:
	-@rm -rvf *.o
endif