M = Main
C = lin_p1
CFLAGS= -std=c++14  -O2 

Main: $(M)

$(M):$(M).o 
	g++ $(M).o  -o $(C)

clean:
	rm -rf *.o  $(C)