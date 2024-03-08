CXX = g++
CXXFLAGS = -Wall -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment
EXECUTABLE = handicap-calculator
SOURCES = $(wildcard *.cpp)

all: 
	$(CXX) $(CXXFLAGS) $(SOURCES) -l sqlite3 -o $(EXECUTABLE)

clean: 
	rm -f *.o handicap-calculator 