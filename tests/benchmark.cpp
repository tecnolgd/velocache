
//command to run benchmark: g++ -O3 src/cache.cpp tests/benchmark.cpp -o build/v_bench

#include <iostream>
#include <chrono>
#include "../include/velocache/cache.hpp" 

void runBenchmark(int operations) {
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < operations; ++i) {
        putValue("user" + std::to_string(i), "data" + std::to_string(i));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; //runtime calculation

    std::cout << "Finished " << operations << " put operations in: " << diff.count() << "s" << std::endl;
    std::cout << "Average speed: " << (operations / diff.count()) << " ops/sec" << std::endl;
}

int main(){
    runBenchmark(10000); //benchmarking cache performance

    return 0;
}