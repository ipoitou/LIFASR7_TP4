all : barriere

barriere: main.o barriere.o
	g++ -g -pthread main.o barriere.o -o barriere

main.o: main.cpp barriere.h
	g++ -g -Wall -pthread -c main.cpp

barriere.o: barriere.h barriere.cpp
	g++ -g -Wall -pthread -c barriere.cpp


clean:
	rm *.o

veryclean: clean
	rm *.out
