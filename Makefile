CXX = g++
CXX_VERSION = -std=c++17
CXXFLAGS = -Wall -Wextra -O2 $(CXX_VERSION)
LDFLAGS = -pthread -lrt

OUTPUT_DIR = build
TARGET = $(OUTPUT_DIR)/app

all: $(TARGET)

$(TARGET): main.cpp
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OUTPUT_DIR)
