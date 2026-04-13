CXX     = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET  = student_management
SRCS    = main.cpp student.cpp fileManager.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
