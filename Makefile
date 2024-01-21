objects =  main.o users.o calculator.o

all: calculator 

calculator: $(objects)
	g++ -o calculator $(objects)

main.o: main.cpp
	g++ -c main.cpp

calculator.o: calculator.cpp calculator.h
	g++ -c calculator.cpp

users.o: users.cpp users.h
	g++ -c users.cpp

clean: 
	rm -f *.o handicap-calculator
	rm -f calculator
