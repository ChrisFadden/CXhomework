OBJS = time_dgemm.o
CC = gcc
CFLAGS = -Wall -c -g  
LFLAGS = -Wall -g -lpthread  
EXE    =  timeDGEMM

timeDGEMM : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE) /opt/openblas-0.2.12/lib/libopenblas_nehalemp-r0.2.12.so

timeDGEMM.o : time_dgemm.c 
	$(CC) $(CFLAGS) time_dgemm.c	

.PHONY : clean
clean:
	-rm $(EXE) $(OBJS)


