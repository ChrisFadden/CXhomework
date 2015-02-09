OBJS = timeDGEMM.o
CC = g++
CFLAGS = -Wall -c -g -std=c++0x 
LFLAGS = -Wall -g -std=c++0x -lpthread -lopenblas 
EXE    =  timeDGEMM

LIBS_PATH = -L./openblas/lib
INC_PATH = -I./openblas/include

timeDGEMM : $(OBJS)
	$(CC) $(INC_PATH) $(LIBS_PATH) $(LFLAGS) $(OBJS) -o $(EXE)

timeDGEMM.o : timeDGEMM.cpp 
	$(CC) $(CFLAGS) timeDGEMM.cpp	

.PHONY : clean
clean:
	-rm $(EXE) $(OBJS)


