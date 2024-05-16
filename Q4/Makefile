CXX=g++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion --coverage
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=dijkstra.cpp main.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o main

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: main
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main *.gcno *.gcda *.gcov
