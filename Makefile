SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))
output: $(OBJ)
	gcc -o $@ $(OBJ) -g -Wall
clean:
	rm *.o output
