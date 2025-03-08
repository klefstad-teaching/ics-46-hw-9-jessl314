CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic


GTEST_INCLUDE = /usr/include/gtest/include
GTEST_LIB = /usr/include/gtest/lib 

EXEC = student_gtests

LDFLAGS = -lgtest -lgtest_main

$(EXEC): src/dijkstras.cpp src/ladder.cpp gtest/student_gtests.cpp
	g++ $(CXXFLAGS) src/dijkstras.cpp src/ladder.cpp gtest/student_gtests.cpp -I$(GTEST_INCLUDE) -L$(GTEST_LIB) $(LDFLAGS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	/bin/rm -f $(EXEC)