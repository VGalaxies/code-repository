.PHONY: clean

CC = gcc
CFLAGS = -Wall -Og -g

OBJ = buddy2.o buddy2_test.o
EXE = buddy2_test

run: $(OBJ)	
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
	./$(EXE)

clean:
	rm -f $(OBJ) $(EXE) 

