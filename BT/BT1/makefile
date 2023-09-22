CC = g++
CFLAGS = -Wall -std=c++11
OBJS = main.o employee.o
TARGET = myprogram

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp employee.h
	$(CC) $(CFLAGS) -c main.cpp

employee.o: employee.cpp employee.h
	$(CC) $(CFLAGS) -c employee.cpp

clean:
	rm -f $(OBJS) $(TARGET)
