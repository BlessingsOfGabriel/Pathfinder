# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O3

all	: bin/pathfinder
	@echo -n ""

# optimized version
bin/pathfinder	: Graph_opt.o main_opt.o lib
	$(CC) $(OPTFLAGS) Graph_opt.o main_opt.o -ltm_usage -Llib -o bin/pathfinder
main_opt.o : src/main.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $< -Ilib -o $@
Graph_opt.o	: src/Graph.cpp src/Graph.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

# DEBUG Version
dbg : bin/pathfinder_dbg
	@echo -n ""

bin/pathfinder_dbg	: Graph_dbg.o main_dbg.o lib
	$(CC) $(DBGFLAGS) Graph_dbg.o main_dbg.o -ltm_usage -Llib -o bin/pathfinder_dbg
main_dbg.o : src/main.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $< -Ilib -o $@
Graph_dbg.o	: src/Graph.cpp src/Graph.h
	$(CC) $(CFLAGS) $(DBGFLAGS) $< -o $@

lib: lib/libtm_usage.a

lib/libtm_usage.a: tm_usage.o
	$(AR) $(ARFLAGS) $@ $<
tm_usage.o: lib/tm_usage.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $<

# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*