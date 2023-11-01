LDFLAGS = (optional flags for the linker)
CXXFLAGS = -Wall  # optional flags for the compiler (eg. -Wall for warnings)
CXXINCLUDES = .

main.exe: main.o dbuffer.o
	g++ $(LDFLAGS) main.o dbuffer.o -o main.exe

# General rule for building object files
%.o: %.cpp
	g++ $(CXXFLAGS) -I$(CXXINCLUDES) -c $< -o $@


.PHONY: clean doc

clean:
	rm -f *.o *.exe

doc:
	doxygen

all: main.exe 
	doc
	valgrind main.exe