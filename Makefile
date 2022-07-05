# needed flags:
V := 0.0.1-pre-alpha
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
OUT_NAME = nacus
SRC = ./src
LIB = ./lib/libneoabacus
LIB_FILES = $(shell find $(LIB)/src -name "*.c")
COMP = $(FLAGS) -o $(BUILD_DIR)/$(OUT_NAME)


# all: build/lib
# 	$(BUILD_DIR)/$(OUT_NAME)

test/lib: pre
	$(CC) -g3 $(LIB_FILES) $(LIB)/test/test.c $(COMP)
	$(BUILD_DIR)/$(OUT_NAME)

build/lib: pre
	$(CC) $(LIB_FILES) $(COMP)

pre:
	mkdir -p $(BUILD_DIR)

overview:
	@printf "test/lib build/lib pre"
