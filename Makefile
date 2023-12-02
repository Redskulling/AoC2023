CXX := g++
CXXFLAGS := -std=c++23 -Wall -Werror -Wextra -pedantic -Wfatal-errors
CXXDEBUGFLAGS := -g -O0
CXXRELEASEFLAGS := -O3
INCLUDES := -I./include

01-par2: 01/part2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 01.out 01/part2.cpp

01-part1: 01/part1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 01.out 01/part1.cpp