CXX = g++

STD = -std=c++17
WARN = -Wall -Wextra

DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

LDFLAGS = -pthread -lrt

OUTPUT_DIR = build
TARGET = $(OUTPUT_DIR)/app

SRC = main.cpp pthread_wrapper.cpp
OBJ = $(SRC:%.cpp=$(OUTPUT_DIR)/%.o)

# ===== build mode =====
BUILD ?= debug

ifeq ($(BUILD),debug)
	CXXFLAGS = $(STD) $(WARN) $(DEBUG_FLAGS)
else
	CXXFLAGS = $(STD) $(WARN) $(RELEASE_FLAGS)
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(OUTPUT_DIR)/%.o: %.cpp
	mkdir -p $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OUTPUT_DIR)
