CXX:=g++
CXXFLAGS:=-g -Wall -pedantic -std=c++11
sources:=$(wildcard src/*.cpp)
headers:=$(wildcard src/*.h)
bin/main.exe: $(sources) $(headers)
	$(CXX) $(CXXFLAGS) -o bin/main.exe $(sources)
	
all: bin/main.exe

tar:
	tar cvf szofttech.tar $(sources) $(headers) Makefile
