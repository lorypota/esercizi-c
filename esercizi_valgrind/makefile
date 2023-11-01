CC = g++  # Compiler
CFLAGS = -Wall  # optional flags for the compiler (eg. -Wall for warnings)
LDFLAGS = #optional flags for the linker
VALGRIND = valgrind #could add command options here

# List of source files without extensions
# EXECS = ex1-uninitmemory ex2-dataaccess ex2-fibonacci ex3-memoryleak ex4-pair ex5-valfail
# still trying to figure out how to utilize this

# Rule for each individual target
1: ex1-uninitmemory.exe
	$(VALGRIND) ./ex1-uninitmemory.exe
	make clean

2: ex2-dataaccess.exe
	$(VALGRIND) ./ex2-dataaccess.exe
	make clean

3: ex2-fibonacci.exe
	$(VALGRIND) ./ex2-fibonacci.exe
	make clean

4: ex3-memoryleak.exe
	$(VALGRIND) ./ex3-memoryleak.exe
	make clean

5: ex4-pair.exe
	$(VALGRIND) ./ex4-pair.exe
	make clean

6: ex5-valfail.exe
	$(VALGRIND) ./ex5-valfail.exe
	make clean

# General rule for building targets
# example: 
#		$@ becomes ex1-uninitinmemory.exe
#		$^ becomes ex1-uninitinmemory.o
# full command becomes: g++ ex1-uninitmemory.o -o ex1-uninitmemory.exe -Wall
%.exe: %.o
	$(CC) $(LDFLAGS) -o $@ $^

# General rule for building object files
# example:
#		$< becomes the .cpp file
#		$@ becomes the .o file
# full command becomes: g++ -c ex1-uninitmemory.cpp -o ex1-uninitmemory.o 
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


# Clean rule to remove object files and executables
.PHONY: clean

clean:
	rm -f *.o *.exe