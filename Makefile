project: main.o asmprogram.o
	g++ main.o -lwiringPi -o project.o

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

asmprogram.o: main.s
	as -o asmprogram.o main.s

clean:
	rm *.o project
