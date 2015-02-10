EXE := mkl-practice

MKLROOT := /canopt/intel/mkl/10.2.2.025
program_C_SRCS := $(wildcard *.c)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_INCLUDE_DIRS := $(MKLROOT)/include
program_LIBRARIES :=
CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
CFLAGS += -O3 -std=c99 -Wall -DMKL_ILP64 -m64 -pedantic #-Werror
LDADD += $(foreach library,$(program_LIBRARIES),-l$(library))
LDADD += $(MKLROOT)/lib/em64t/libmkl_solver_ilp64_sequential.a -Wl,--start-group $(MKLROOT)/lib/em64t/libmkl_intel_ilp64.a $(MKLROOT)/lib/em64t/libmkl_core.a $(MKLROOT)/lib/em64t/libmkl_sequential.a -Wl,--end-group -lpthread -lm
CFLAGS += $(EXTRA_FLAGS)
LDFLAGS := 
CC := gcc

.PHONY: all clean distclean

all: $(EXE)

debug: CFLAGS = -g -O0 -std=c99 -Wall -DMKL_ILP64 -m64 -pedantic $(EXTRA_FLAGS)
debug: $(EXE)

$(EXE): $(program_C_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(program_C_OBJS) $(LDADD) -o $(EXE)

clean:
	@- $(RM) $(EXE) $(program_C_OBJS) *~

distclean: clean