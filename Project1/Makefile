M = Main
C = lin_p1
CFLAGS= -std=c++14  -O2 

lin_p1: $(M)

$(M):$(M).o 
	g++ $(M).o  -o $(C)


clean:
	rm -rf *.o  $(C)