a.out: main.o LeakDetector.o
	g++ -o a.out main.o LeakDetector.o
main.o: main.cpp LeakDetector.h
	g++ -c main.cpp
LeakDetector.o: LeakDetector.cpp LeakDetector.h
	g++ -c LeakDetector.cpp LeakDetector.h
clean:
	rm *.o
