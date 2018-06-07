CXX=clang++-5.0
CXXFLAGS=-std=c++17

make:
	$(CXX) $(CXXFLAGS) --compile TestCase.cpp -o TestCase.o
	$(CXX) $(CXXFLAGS) -c main.cpp
	$(CXX) $(CXXFLAGS) *.o -o a.out
	
run:	
	./a.out

clean:
	rm *.o a.out