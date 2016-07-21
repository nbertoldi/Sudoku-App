CC	:= g++
CFLAGS	:= -std=c++11 -g
LIBFILE := A.cc
EXEC	:= solver.cc

run : $(EXEC) $(LIBFILE)
	$(CC) $(LIBFILE) $(EXEC) $(CFLAGS) -o solver
