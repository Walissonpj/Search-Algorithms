exec: Main.o CPUTimer.o
	g++ -O -o exec Main.o CPUTimer.o

Main.o: Main.cpp
	g++ -O -c Main.cpp -w -lm
CPUTimer.o: CPUTimer.cpp
	g++ -O -c CPUTimer.cpp -w -lm
clean:
	rm exec Main.o CPUTimer.o
