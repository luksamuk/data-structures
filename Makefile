CC     := clang
CFLAGS := -g -Wall -Wextra -pedantic
SRC    := $(wildcard src/*.c)
OBJ    := $(SRC:%.c=%.o)
BIN    := bin/ds_test.out

.PHONY: dirs clear delete

all: dirs $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

dirs:
	mkdir -p bin/

clear:
	rm -rf obj/*

delete:
	rm $(BIN)
