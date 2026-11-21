CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
TARGET = $(BIN_DIR)/cell

# Recursively find all .c files inside src/ and its subdirectories
SRCS = $(shell find $(SRC_DIR) -type f -name '*.c')

# Map src/path/to/file.c to build/obj/path/to/file.o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: directories $(TARGET)

directories:
	@mkdir -p $(BIN_DIR)
	@# Automatically create all required object subdirectories
	@mkdir -p $(dir $(OBJS))

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Pattern rule that handles nested subdirectories
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all directories run clean