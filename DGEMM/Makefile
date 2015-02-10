OBJS = Time_dgemm.o
CC = g++
CFLAGS = -Wall -c -g  
LFLAGS = -Wall -g -lpthread  
EXE    =  timeDGEMM

timeDGEMM : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE) /opt/openblas-0.2.12/lib/libopenblas_nehalemp-r0.2.12.so

timeDGEMM.o : Time_dgemm.cpp 
	$(CC) $(CFLAGS) Time_dgemm.cpp	

.PHONY : clean
clean:
	-rm $(EXE) $(OBJS)


