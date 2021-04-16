ifeq ($(OS), Windows_NT)
TARGET=program.exe
else
TARGET=program
endif

LIBPATH=lib
OBJPATH=obj
FRTPATH=fortran

MAIN=main.c
MAINF=$(FRTPATH)/findsubstring.f90

SRC=$(wildcard $(LIBPATH)/*.c)
OBJ=$(SRC:$(LIBPATH)/%.c=$(OBJPATH)/%.o)
OBJF=$(MAINF:$(FRTPATH)/%.f90=$(OBJPATH)/%.o)
CC=gcc
GF=gfortran

# chama tudo
all: $(TARGET) clear

# compila os objetos do C com o main.c e o objeto do fortran
$(TARGET): $(OBJF) $(OBJ)
	$(CC) $(MAIN) $(OBJF) $(OBJ) -o $@ -lgfortran

# gera o objeto do fortran
$(OBJF): $(MAINF)
	$(GF) -c $^ -o $@

# gera os objetos do c
$(OBJ): $(SRC)
	$(CC) -c $< -o $@

# exclui os objetos
# -@del /f /a $(OBJ)
# -@del /f /a $(OBJF)
 
ifeq ($(OS), Windows_NT)
clear:
	-@rm ./$(OBJ)
	-@rm ./$(OBJF)
else
clear:
	-@rm -rvf $(OBJ)
	-@rm -rvf $(OBJF)
endif