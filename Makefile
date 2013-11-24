CXX:=g++
CXXFLAGS:=-g -Wall -pedantic -std=c++11
sources:=$(wildcard src/*.cpp)
headers:=$(wildcard src/*.h)
main: $(sources) $(headers)
	$(CXX) $(CXXFLAGS) -o bin/main $(sources)
	
all: main

tar:
	tar cvf szofttech.tar $(sources) $(headers) Makefile
