SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

CXX = g++
CXXFLAGS = -O2 -g

all: $(PROGS)

%: %.c
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)