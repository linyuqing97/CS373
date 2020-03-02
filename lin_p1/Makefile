M = lin_p1
CFLAGS= -std=c++11  -O2 

lin_p1: $(M)

$(M):$(M).o 
	g++  $(M).o  -o $(M)

$(M).o::$(M).cpp
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o
clean:
	rm -rf *.o  $(M)