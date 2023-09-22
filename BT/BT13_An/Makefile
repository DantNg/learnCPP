CC = gcc
CFLAGS = -Wall

all: main.o Application.o Intern.o Employee.o Certificate.o Fresher.o Experience.o ManageEmployee.o
    $(CC) $(CFLAGS) -o my_program main.o functions.o

main.o: main.cpp 
    $(CC) $(CFLAGS) -g main.cpp

Application.o: Application.cpp 
    $(CC) $(CFLAGS) -g Application.cpp
    
Intern.o: Intern.cpp 
    $(CC) $(CFLAGS) -g Intern.cpp
Employee.o: Employee.cpp 
    $(CC) $(CFLAGS) -g Employee.cpp
Certificate.o: Certificate.cpp 
    $(CC) $(CFLAGS) -g Certificate.cpp
Fresher.o: Fresher.cpp
    $(CC) $(CFLAGS) -g Fresher.cpp
ManageEmployee.o: ManageEmployee.cpp
    $(CC) $(CFLAGS) -g ManageEmployee.cpp
Experience.o: Experience.cpp
    $(CC) $(CFLAGS) -g Experience.cpp
clean:
    rm -f *.o my_program
