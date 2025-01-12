.SUFFIXES: .cpp $(SUFFIXES)
COMPILER = clang++
CPPFLAGS = --stdlib=libc++ -std=c++20

all: example

example : example.o
	$(COMPILER) $(CPPFLAGS) example.o

.cpp.o:
	$(COMPILER) $(CPPFLAGS) -c $<

clean :
	-rm *.o *~ a.out
