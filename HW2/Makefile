OBJS = main.o matrix.o
HEADERS = matrix.h 
CC = g++
CFLAGS = -Wall -c -g -std=c++11 -fopenmp 
LFLAGS = -Wall -g -std=c++11 -lpthread -fopenmp
EXE    =  matrix

matrix : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) main.cpp

matrix.o : matrix.cpp $(HEADERS)
	$(CC) $(CFLAGS) matrix.cpp

.PHONY : clean
clean:
	-rm $(EXE) $(OBJS)


