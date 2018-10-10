 OPT = -O1 				

default: all

all: cachetest1 cachetest2

# use different targets for the different assignment tasks
# example:
cachetest1: cachetest1.o 
	gcc $(OPT) -o cachetest1 cachetest1.o

cachetest1.o: cachetest1.c
	gcc $(OPT) -c cachetest1.c

cachetest2: cachetest2.o 
	gcc $(OPT) -o cachetest2 cachetest2.o

cachetest2.o: cachetest2.c
	gcc $(OPT) -c cachetest2.c

clean:
	rm -f *.o
	rm -f cachetest1
	rm -f cachetest2

