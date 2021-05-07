CXX = g++
CXXFLAGS = --std=c++17 -g

SOURCES = function.cpp instruction.cpp utils.cpp architecture.cpp language.cpp main.cpp 
INCLUDES = function.hpp instruction.hpp utils.hpp architecture.hpp language.hpp
OBJECTS = function.o instruction.o utils.o main.o architecture.o language.o

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

%.cpp:
	touch $@

decompile: $(OBJECTS)
	$(CXX) $(OBJECTS) -o decompile

all: decompile

clean:
	rm -f $(OBJECTS)
	rm -f decompile

format:
	clang-format -i $(SOURCES) $(INCLUDES)
