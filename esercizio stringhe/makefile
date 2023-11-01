CXXFLAGS = -O3 -DNDEBUG

CXXINCLUDES = ./include

main.exe: main.o stringheC.o
	g++ $(CXXFLAGS) main.o stringheC.o -o main.exe

main.o: main.cpp
	g++ $(CXXFLAGS) -I$(CXXINCLUDES) -c main.cpp -o main.o

stringheC.o: src/stringheC.cpp
	g++ $(CXXFLAGS) -I$(CXXINCLUDES) -c src/stringheC.cpp -o stringheC.o

.PHONY: clean doc all

clean:
	rm *.o *.exe

doc:
	doxygen

all: main.exe doc