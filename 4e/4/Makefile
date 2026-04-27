# 1. Compiler and flags (with debugging enabled)
CC = gcc
CFLAGS = -Wall -Wextra -g

# 2. Directories for clean output
BIN_DIR = bin
BUILD_DIR = build

# 3. Automatic Executable Naming
# Grabs the name of the folder this Makefile is inside
PROJECT_NAME = $(notdir $(CURDIR))
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

# 4. Find all .c files in this specific folder
SRCS = $(wildcard *.c)

# 5. Map .o files to the build folder
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default rule: build the executable
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c files into .o files
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rules to create the directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to completely clean up generated files
clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)