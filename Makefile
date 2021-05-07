CXX = g++
CXXFLAGS = --std=c++17 -g

OBJECTS = function.o instruction.o utils.o main.o

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
