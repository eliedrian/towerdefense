SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = towerdefense

.PHONY: clean run

$(TARGET): $(OBJS)
	g++ -O2 $^ -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -o $@

$(OBJS): $(SRCS) $(HEADERS)
	g++ -O2 -c $^ -ISFML/include

clean:
	rm $(OBJS) $(TARGET)

run:
	LD_LIBRARY_PATH=SFML/lib ./$(TARGET)
