# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g3

# Target executable
TARGET = matrix_program

# Source files
SRCS = main.cpp matrix.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule: Compile and link
all: $(TARGET)

# Link the object files into an executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program (optional rule)
run: $(TARGET)
	./$(TARGET)
