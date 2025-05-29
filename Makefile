CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET_DBMS = build/axisql
TARGET_CLI = build/axiscli

all: $(TARGET_DBMS) $(TARGET_CLI)

$(TARGET_DBMS): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET_DBMS)

$(TARGET_CLI): src/cli/main.o src/database.o
	$(CC) $(CFLAGS) src/cli/main.o src/database.o -o $(TARGET_CLI)

runCli:
	./build/axiscli.exe

clean:
	rm -f src/*.o src/cli/*.o $(TARGET_DBMS) $(TARGET_CLI)
