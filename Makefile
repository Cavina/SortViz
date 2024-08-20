SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play

# Include paths
INCLUDE_PATHS = -Iinclude -Iinclude/SDL2

# Library paths (update these to point to your symlinked libraries)
LIBRARY_PATHS = -Llib/SDL2 -Llib/SDL2_image

# Compiler and linker flags
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g $(INCLUDE_PATHS)
LINKER_FLAGS = $(LIBRARY_PATHS) -lSDL2 -lSDL2_image

all: $(BUILD_DIR)/$(OBJ_NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(OBJ_NAME): $(SRC_FILES) | $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SRC_FILES) $(LINKER_FLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
