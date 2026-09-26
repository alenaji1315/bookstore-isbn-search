CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
SRC = src/main.c
BIN = bookstore_search
OUTPUT = output/output.txt

.PHONY: all run clean

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

run: $(BIN)
	./$(BIN) | tee $(OUTPUT)

clean:
	rm -f $(BIN)
