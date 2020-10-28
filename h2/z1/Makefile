SRC=$(wildcard src/*c)
EXESRC = $(wildcard exesrc/*c)
OBJ=$(patsubst %c, %o, $(SRC))

INC=inc/
NUMBERS = 1 2 3 4

CFLAGS=-I $(INC)
EXE= exe/test01.elf exe/test02.elf exe/test03.elf exe/test04.elf exe/test05.elf exe/test06.elf exe/test07.elf exe/test08.elf exe/test_dft.elf exe/test_idft.elf

.SECONDARY:

all: $(EXE)

exe/%.elf:  exesrc/%.o $(OBJ)
	gcc -I inc/ $< $(OBJ) -o $@ -lm -w

%.o: %.c
	gcc -c -I inc/ $< -o $@ -lm -w

clean:
	rm -f exesrc/*.o src/*.o $(EXE)
	
run:
	@./exe/test01.elf;
	@./exe/test02.elf;
	@./exe/test03.elf;
	@./exe/test04.elf;
	@./exe/test05.elf;
	@./exe/test06.elf;
	@./exe/test07.elf;
	@./exe/test08.elf;
	@./exe/test_dft.elf;
	@./exe/test_idft.elf;
