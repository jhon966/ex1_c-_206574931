SRC_DIRS := Algorithms Graph DataStructures Tests

SRC := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp)) mian.cpp

OBJ := $(SRC:.cpp=.o)

BIN := main

CXX := g++
CXXFLAGS := -Wall -std=c++17 -g $(foreach dir,$(SRC_DIRS),-I$(dir))

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: $(BIN)
	valgrind --leak-check=full ./$(BIN)

# ניקוי קבצים זמניים
clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean valgrind