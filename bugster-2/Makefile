CC = g++

OBJS = bugbuster2.o \
	misc.o 

bugbuster2.exe : $(OBJS)
	$(CC) $(OBJS) -o bugbuster2.exe

bugbuster2.o : bugbuster2.cpp misc.h
	$(CC) -c bugbuster2.cpp -o bugbuster2.o

misc.o : misc.cpp misc.h
	$(CC) -c misc.cpp -o misc.o	

.PHONY: clean

clean:
	rm -f *.d *.o *.exe
