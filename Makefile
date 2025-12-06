CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17
LDFLAGS = -pthread -lrt

OUTPUT_DIR = build
TARGET = $(OUTPUT_DIR)/app

SRC = main.cpp pthread_wrapper.cpp
OBJ = $(SRC:%.cpp=$(OUTPUT_DIR)/%.o)

all: $(TARGET)

# Build final binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile .cpp → .o
$(OUTPUT_DIR)/%.o: %.cpp
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OUTPUT_DIR)
