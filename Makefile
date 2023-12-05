CXX := g++
CXXFLAGS := -std=c++23 -Wall -Werror -Wextra -pedantic -Wfatal-errors
CXXDEBUGFLAGS := -g -O0
CXXRELEASEFLAGS := -O3
INCLUDES := -I./include

04-part1: 04/part1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 04.out 04/part1.cpp

03-part2: 03/part2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 03.out 03/part2.cpp

03-part1: 03/part1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 03.out 03/part1.cpp

02-part2: 02/part2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 02.out 02/part2.cpp

02-part1: 02/part1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 02.out 02/part1.cpp

01-part2: 01/part2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 01.out 01/part2.cpp

01-part1: 01/part1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXRELEASEFLAGS) -o 01.out 01/part1.cpp
