SRC_DIR = src
BUILD_DIR = build/debug
CC = g++-13
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib/SDL2 -Llib/SDL2_image 
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lstdc++

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)