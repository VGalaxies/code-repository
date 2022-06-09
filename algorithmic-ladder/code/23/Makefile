CC = g++
CXXFLAGS = -O2 -Wall

.PHONY: run clean

OBJ = main.o
EXE = main

run: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJ)
