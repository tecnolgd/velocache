CC = g++
CFLAGS = -I./include -O3 # -O3 tells the compiler to optimize for MAX SPEED

all: v_server v_bench

v_server: src/cache.cpp src/storage.cpp apps/server.cpp utils/input_validation.cpp
	$(CC) $(CFLAGS) src/cache.cpp src/storage.cpp apps/server.cpp utils/input_validation.cpp -o build/v_server

v_bench: src/cache.cpp tests/benchmark.cpp
	$(CC) $(CFLAGS) src/cache.cpp tests/benchmark.cpp -o build/v_bench

clean:
	rm -f v_server v_bench