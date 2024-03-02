# Compiler setup
CXX = g++-13
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic
INCLUDES = -Isrc
LIBS =

# Base directory setup
SRC_DIR =  .
BUILD_DIR = build

# Discover all source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

.PHONY: all clean fast dev debug ubsan asan

# Default target to build all flavours
all: fast dev debug ubsan asan

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Individual build flavours
fast: CXXFLAGS += -O3 -DNDEBUG
fast: TARGET = $(BUILD_DIR)/fast/my_app
fast: build

dev: CXXFLAGS += -ggdb -O0
dev: TARGET = $(BUILD_DIR)/dev/my_app
dev: build

debug: CXXFLAGS += -ggdb -O3
debug: TARGET = $(BUILD_DIR)/debug/my_app
debug: build

ubsan: CXXFLAGS += -ggdb -fsanitize=undefined
ubsan: TARGET = $(BUILD_DIR)/ubsan/my_app
ubsan: build

asan: CXXFLAGS += -ggdb -fsanitize=address
asan: TARGET = $(BUILD_DIR)/asan/my_app
asan: build


# Generic build rule
build:
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET) $(LIBS)

