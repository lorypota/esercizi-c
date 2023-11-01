CC = g++  # Compiler
CXXFLAGS = -Wall  # optional flags for the compiler (eg. -Wall for warnings)
LDFLAGS = #(optional flags for the linker)
VALGRIND = valgrind

# Rule for each target
1: 1.exe
	$(VALGRIND) ./1.exe
	make clean

2_solo_puntatori: 2_solo_puntatori.exe
	$(VALGRIND) ./2_solo_puntatori.exe
	make clean

2: 2.exe
	$(VALGRIND) ./2.exe
	make clean

3: 3.exe
	$(VALGRIND) ./3.exe
	make clean

# General rule for building targets
%.exe: %.o
	$(CC) $(LDFLAGS) -o $@ $^

# General rule for building object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@


# Clean rule to remove object files and executables
.PHONY: clean doc

clean:
	rm -f *.o *.exe

doc:
	doxygen