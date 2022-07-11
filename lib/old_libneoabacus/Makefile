CC := gcc

FLAGS = -fdiagnostics-color=always  \
							 -Wall \
							 -Wpedantic \
							 -std=c18 \
							 -Wextra \
							 -Werror \
							 -Wshadow \
							 -Wundef \
							 -lm \
							 -fno-common

BUILD_DIR = ./out
LIB = .
LIB_FILES = $(shell find $(LIB)/src -name "*.c")
COMP = $(FLAGS) -o $(BUILD_DIR)/tests

test/lib: pre
	$(CC) -g3 $(LIB_FILES) $(LIB)/test/test.c $(COMP)
	$(BUILD_DIR)/tests

build/lib: pre
	$(CC) $(LIB_FILES) $(COMP)

pre:
	mkdir -p $(BUILD_DIR)
