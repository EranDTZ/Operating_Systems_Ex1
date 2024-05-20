TARGET = maxsub
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++11 -pg
LDFLAGS = -pg
SRCS = main.cpp MaxSub_alg.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) gmon.out 

.PHONY: all clean run
