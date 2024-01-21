all: handicap-calculator

handicap-calculator: handicap-calculator.o
	g++ -o handicap-calculator handicap-calculator.o

handicap-calculator.o: handicap-calculator.cpp handicap-calculator.h
	g++ -c handicap-calculator.cpp
