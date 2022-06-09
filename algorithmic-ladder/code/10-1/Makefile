CC = g++
CXXFLAGS = -g -Og -Wall

.PHONY: run clean

OBJ = main.o
EXE = main

run: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJ)
