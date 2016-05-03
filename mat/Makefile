CFLAGS = -Wall -std=c++11 -O2
CC = g++

all: gauss cond gen relax zeidel jacobi

debug: CFLAGS += -DDEBUG -g
debug: all

clean:
	rm -f gauss
	rm -f cond
	rm -f gen
	rm -f relax
	rm -f zeidel
	rm -f jacobi

cond: cond.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
gauss: gauss.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
gen: gen.cpp
	$(CC) $(CFLAGS) $^ -o $@

relax: relax.cpp
	$(CC) $(CFLAGS) $^ -o $@

zeidel: zeidel.cpp
	$(CC) $(CFLAGS) $^ -o $@

jacobi: jacobi.cpp
	$(CC) $(CFLAGS) $^ -o $@
