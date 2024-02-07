CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment
EXECUTABLE = handicap-calculator
SOURCES = $(wildcard *.cpp)

all: 
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE) 

clean: 
	rm -f *.o handicap-calculator 