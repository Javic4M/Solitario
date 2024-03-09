CXX = g++
CXXFLAGS = -std=c++17

SRCS = Solitario.cpp
OBJS = $(SRCS:.cpp=.exe)
TARGET = Solitario

all:
	$(CXX) $(SRCS) -o $(TARGET) $(CXXFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)