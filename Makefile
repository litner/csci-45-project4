project: main.o
	g++ main.o -lwiringPi -o project.o

main.o: main.cpp
	g++ -c -std=c++11 main.cpp -lwiringPi

clean:
	rm *.o
