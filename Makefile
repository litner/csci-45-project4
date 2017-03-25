project: main.o
	g++ main.o -lwiringPi -o project.o

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

clean:
	rm *.o project
