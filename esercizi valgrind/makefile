CC = g++  # Compiler
CFLAGS = -Wall  # Compiler flags, e.g., for warnings
VALGRIND = valgrind #could add command options here

# Rule to build all objects and executables
all: 
	make 1
	make 2
	make 3
	make 4
	make 5
	make 6

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
#		$@ becomes ex1-unitinmemory.exe
#		$^ becomes ex1-unitinmemory.o
# full command becomes: g++ ex1-uninitmemory.o -o ex1-uninitmemory.exe -Wall
ex1-uninitmemory.exe: ex1-uninitmemory.o
	$(CC) $(CFLAGS) -o $@ $^

ex2-dataaccess.exe: ex2-dataaccess.o
	$(CC) $(CFLAGS) -o $@ $^

ex2-fibonacci.exe: ex2-fibonacci.o
	$(CC) $(CFLAGS) -o $@ $^

ex3-memoryleak.exe: ex3-memoryleak.o
	$(CC) $(CFLAGS) -o $@ $^

ex4-pair.exe: ex4-pair.o
	$(CC) $(CFLAGS) -o $@ $^

ex5-valfail.exe: ex5-valfail.o
	$(CC) $(CFLAGS) -o $@ $^

# General rule for building object files
# example:
#		$< becomes the .cpp file
#		$@ becomes the .o file
# full command becomes:
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


# Clean rule to remove object files and executables
.PHONY: clean

clean:
	rm -f *.o *.exe