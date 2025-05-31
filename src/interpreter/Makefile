CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC_DIR = ..
FNC_DIR = $(SRC_DIR)/fnc
BIN = axisql

SRC_FILES = interpreter.c $(wildcard $(FNC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

$(BIN): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(BIN)
