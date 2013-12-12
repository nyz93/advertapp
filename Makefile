CXX:=g++
CXXFLAGS:=-g -Wall -pedantic -std=c++11
sources:=$(wildcard src/*.cpp)
headers:=$(wildcard src/*.h)
objects:=$(sources:.cpp=.o)


src/%.o: src/%.cpp src/%.h
	@echo "$< -> $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

src/%.o: src/%.cpp
	@echo "$< -> $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

bin/main.exe: $(objects)
	@mkdir -p bin
	@echo "$(objects) -> bin/main.exe"
	@$(CXX) -o bin/main.exe $(objects)
	
all: bin/main.exe

clean:
	find ./bin/ -name 'main.exe' -exec rm {} ';'
	find ./src/ -type f -name "*.o" -exec rm {} ';'

tar:
	tar cvf szofttech.tar $(sources) $(headers) Makefile main.db
