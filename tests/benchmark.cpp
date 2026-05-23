
//command to run benchmark: g++ -O3 src/cache.cpp tests/benchmark.cpp -o build/v_bench

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include "../include/cache.hpp" 

void runBenchmark(int operations) {
    std::vector<double> latencies;
    latencies.reserve(operations); // Allocate memory upfront to prevent reallocations from skewing latency

    auto totalStart = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < operations; ++i) {
        std::string key = "user" + std::to_string(i);
        std::string val = "data" + std::to_string(i);

        // Track precise latency per individual operation
        auto opStart = std::chrono::high_resolution_clock::now();
        putValue(key, val);
        auto opEnd = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> opDiff = opEnd - opStart; // Microseconds are ideal for O(1) ops
        latencies.push_back(opDiff.count());
    }

    auto totalEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalDiff = totalEnd - totalStart;

    // Sort latencies to calculate percentiles
    std::sort(latencies.begin(), latencies.end());

    // Calculate core latency metrics
    double avgLatency = (totalDiff.count() * 1000000.0) / operations; // Convert total to microseconds avg
    double p50 = latencies[static_cast<int>(operations * 0.50)];       // Median
    double p95 = latencies[static_cast<int>(operations * 0.95)];       // Tail Latency 95%
    double p99 = latencies[static_cast<int>(operations * 0.99)];       // Tail Latency 99%

    // Output Performance Analysis
    std::cout << "================================================\n";
    std::cout << "            velocache Benchmark Run             \n";
    std::cout << "================================================\n";
    std::cout << "Total Operations : " << operations << " puts\n";
    std::cout << "Total Runtime    : " << totalDiff.count() << "s\n";
    std::cout << "Throughput       : " << (operations / totalDiff.count()) << " ops/sec\n\n";
    
    std::cout << "Latency Metrics (Microseconds):\n";
    std::cout << "  Average        : " << avgLatency << " μs\n";
    std::cout << "  p50 (Median)   : " << p50        << " μs\n";
    std::cout << "  p95 Tail       : " << p95        << " μs\n";
    std::cout << "  p99 Tail       : " << p99        << " μs\n";
    std::cout << "================================================\n";
}

int main(){
    runBenchmark(10000); // benchmarking cache performance
    return 0;
}