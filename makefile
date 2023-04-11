TARGET = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CC = g++
CCFLAGS = -std=c++11 

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.exe
