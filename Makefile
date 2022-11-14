SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
PRECOMP_HEADERS = $(HEADERS:.h=.h.gch)
OBJS = $(SRCS:.cpp=.o)
TESTS = $(wildcard tests/*.cpp)
TEST_OBJS = $(TESTS:.cpp=.o)
CMAKE_BUILD_DIR = build/
GTEST_TARGET = build/towerdefense_tests
TARGET = towerdefense
TEST_TARGET = towerdefense_tests

.PHONY: clean run test

run: $(TARGET)
	LD_LIBRARY_PATH=SFML/lib ./$(TARGET)

$(TARGET): $(OBJS)
	g++ $^ -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -o $@

$(OBJS): $(SRCS) $(HEADERS)
	g++ -c $^ -ISFML/include

$(TEST_OBJS): $(TESTS)
	g++ -c $^ -o $@

$(TEST_TARGET): $(TEST_OBJS)
	g++ $^ -o $@

$(GTEST_TARGET): $(TESTS)
	cmake -S . -B $(CMAKE_BUILD_DIR)
	cmake --build $(CMAKE_BUILD_DIR)

clean:
	rm -rf $(OBJS) $(TARGET) $(TEST_TARGET) $(TEST_OBJS) $(CMAKE_BUILD_DIR) $(PRECOMP_HEADERS)

test: $(GTEST_TARGET)
	./$^
