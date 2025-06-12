CC = cc
CFLAGS = -Wall -Iinclude
SRC = src/cprintf.c generated/handlers.c
OUT = cprintf

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT) generated/handlers.c

