#!make -f

CXX=clang++-9
CXXFLAGS=-std=c++2a

OBJECTS=mat.o
SOURCES=mat.cpp

run: test
	./$^

test: TestRunner.o StudentTest1.o StudentTest2.o StudentTest3.o $(OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

main: Main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Ohad Madei
StudentTest1.cpp:  
	curl https://raw.githubusercontent.com/Ohad-Ma/carpets-maker-1/master/Test.cpp > $@

# Dvir Biton
StudentTest2.cpp: 
	curl https://raw.githubusercontent.com/dvirBiton1/cpp-Ex1-part1/main/Test.cpp > $@

# Gilad Livshitz
StudentTest3.cpp: 
	curl https://raw.githubusercontent.com/giladliv/Maarachot-B-Task-01/main/Test.cpp > $@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=* --

clean:
	rm -f *.o test
	rm -f StudentTest*.cpp
