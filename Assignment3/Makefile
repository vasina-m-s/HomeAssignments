PROJECT = transformers
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Werror -I.
LDFLAGS = -lgtest -lgtest_main -pthread

SRC = Transformer.cpp Autobot.cpp Decepticon.cpp Maximal.cpp Gun.cpp Battle.cpp
OBJ = $(SRC:.cpp=.o)

MAIN_CPP = main.cpp
MAIN_OBJ = $(MAIN_CPP:.cpp=.o)

TESTS = transformer_test.cpp
TEST_OBJ = $(TESTS:.cpp=.o)

TARGET = transformers
TEST_TARGET = tests

$(TARGET): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(MAIN_OBJ)

$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(TEST_OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET) Transformers

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)