CC=gcc
CFLAGS=-Wall -Wextra -O2

all: app

app: main.c gcd.c inverse.c exponent.c
	$(CC) $(CFLAGS) main.c gcd.c inverse.c exponent.c -o app

clean:
	rm -f app *.o
