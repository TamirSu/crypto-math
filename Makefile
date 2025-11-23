
CC=gcc
CFLAGS=-Wall -Wextra -O2 -std=c11
SRCS = main.c gcd.c inverse.c solve_system.c exponent.c solve_mod_pq.c random_prime.c
OBJS = $(SRCS:.c=.o)

all: app

app: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o app

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f app $(OBJS)

.PHONY: all clean test

test: app
	@echo "Running unit tests..."
	./app
