

EXE := mkl-practice
CC := gcc
CFLAGS += -O3 -std=c99 -Wall -DMKL_ILP64 -fopenmp -m64 -pedantic
MKLROOT := /canopt/intel/mkl/10.2.2.025

program_INCLUDE_DIRS := $(MKLROOT)/include
program_LINK_DIRS := 
program_LIBRARIES :=

program_C_SRCS := $(wildcard *.c)
program_C_OBJS := ${program_C_SRCS:.c=.o}

CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach dir,$(program_LINK_DIRS),-L$(dir))
LDADD += $(foreach library,$(program_LIBRARIES),-l$(library))
LDADD += $(MKLROOT)/lib/em64t/libmkl_solver_ilp64.a -Wl,--start-group $(MKLROOT)/lib/em64t/libmkl_intel_ilp64.a $(MKLROOT)/lib/em64t/libmkl_core.a $(MKLROOT)/lib/em64t/libmkl_gnu_thread.a -Wl,--end-group -lpthread -lm
CFLAGS += $(EXTRA_FLAGS)


.PHONY: all clean distclean

all: $(EXE)

debug: CFLAGS = -g -O0 -std=c99 -Wall -DMKL_ILP64 -fopenmp -m64 -pedantic $(EXTRA_FLAGS)
debug: $(EXE)

$(EXE): $(program_C_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(program_C_OBJS) $(LDADD) -o $(EXE)

clean:
	@- $(RM) $(EXE) $(program_C_OBJS) *~

distclean: clean