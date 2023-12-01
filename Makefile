CXX := g++
CXXFLAGS := -std=c++23 -Wall -Werror -Wextra -pedantic -Wfatal-errors
CXXDEBUGFLAGS := -g -O0
CXXRELEASEFLAGS := -O3
INCLUDES := -I./include

01: 01/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXXDEBUGFLAGS) -o 01.out 01/main.cpp