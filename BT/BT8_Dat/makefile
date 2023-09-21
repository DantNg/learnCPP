CC = gcc
CFLAGS = -Wall
all: main.o LibraryManagement.o Card.o Student.o Application.o
    $(CC) $(CFLAGS) -o my_program main.o functions.o

main.o: main.cpp 
    $(CC) $(CFLAGS) -g main.cpp

LibraryManagement.o: LibraryManagement.cpp 
    $(CC) $(CFLAGS) -g LibraryManagement.cpp
Card.o: Card.cpp
	$(CC) $(CFLAGS) -g Card.cpp
Student.o: Student.cpp
	$(CC) $(CFLAGS) -g Student.cpp
Application.o: Application.cpp
	$(CC) $(CFLAGS) -g Application.cpp
clean:
    rm -f *.o my_program