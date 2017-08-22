.DEFAULT_GOAL := all

CC=gcc
CFLAGS=-I./include  -lcheck_pic -pthread -lrt -lm 
ODIR=build




$(ODIR)/Collection.o: src/Collection.c  
	$(CC) -c -o $(ODIR)/Collection.o src/Collection.c  $(CFLAGS) 


$(ODIR)/collection_tests: $(ODIR)/Collection.o
	gcc -o  $(ODIR)/collection_tests $(ODIR)/Collection.o  test/collection_tests.c $(CFLAGS)

.PHONY: clean all default

default: all


clean:
	rm $(ODIR)/* -rf 
	
 
all: clean $(ODIR)/collection_tests
	cp run_tests.sh build
	cd build ;./run_tests.sh
	
 
