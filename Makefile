CC = g++
CFLAGS = -I./include -O3 -Wall# -O3 tells the compiler to optimize for MAX SPEED
# Wall: adds useful warnings for keeping the code clean

#defining the headers so the Makefile tracks changes
DEPS = include/cache.hpp include/common.hpp include/utils.hpp

BUILD_DIR = build

all: $(BUILD_DIR) v_server v_bench
#'all' target ensures the build directory exists before compiling

#create '/build' if it doesn't exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

v_server: src/cache.cpp src/storage.cpp apps/server.cpp utils/input_validation.cpp $(DEPS)
	$(CC) $(CFLAGS) src/cache.cpp src/storage.cpp apps/server.cpp utils/input_validation.cpp -o $(BUILD_DIR)/v_server

v_bench: src/cache.cpp tests/benchmark.cpp $(DEPS)
	$(CC) $(CFLAGS) src/cache.cpp tests/benchmark.cpp -o $(BUILD_DIR)/v_bench

clean:
	rm -rf v_server v_bench