OBJS = timeDGEMM.o
CC = g++
CFLAGS = -Wall -c -g -std=c++0x 
LFLAGS = -Wall -g -std=c++0x -lpthread -lopenblas 
EXE    =  timeDGEMM

timeDGEMM : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

timeDGEMM.o : timeDGEMM.cpp 
	$(CC) $(CFLAGS) timeDGEMM.cpp	

.PHONY : clean
clean:
	-rm $(EXE) $(OBJS)


