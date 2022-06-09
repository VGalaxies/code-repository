.PHONY: run clean gdb

run: test.cpp
	g++ -g -std=c++17 test.cpp
	./a.out

gdb: test.cpp
	g++ -g -std=c++17 test.cpp
	gdb ./a.out

clean:
	rm -f *.out
