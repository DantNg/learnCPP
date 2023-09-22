CC = g++
CFLAGS = -Wall -g

all: main.o Student.o LibraryCard.o LibraryMS.o UserInterface.o
	$(CC) $(CFLAGS) -o main main.o Student.o LibraryCard.o LibraryMS.o UserInterface.o

main.o:
	$(CC) $(CFLAGS) -c main.cpp

Student.o:
	$(CC) $(CFLAGS) -c Model\Student.cpp

LibraryCard.o:
	$(CC) $(CFLAGS) -c Model\LibraryCard.cpp

LibraryMS.o:
	$(CC) $(CFLAGS) -c Controller\LibraryMS.cpp

UserInterface.o:
	$(CC) $(CFLAGS) -c View\UserInterface.cpp
