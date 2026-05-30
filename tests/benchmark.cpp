
//command to run benchmark: g++ -O3 src/cache.cpp tests/benchmark.cpp -o build/v_bench

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include "../include/cache.hpp" 
#include "../include/utils.hpp"

void printMetrics(const std::string& opName, int operations, double totalTime, std::vector<double>& latencies) {
    std::sort(latencies.begin(), latencies.end());

    double avgLatency = (totalTime * 1000000.0) / operations;
    double p50 = latencies[static_cast<int>(operations * 0.50)];
    double p95 = latencies[static_cast<int>(operations * 0.95)];
    double p99 = latencies[static_cast<int>(operations * 0.99)];

    std::cout << "  " << opName << " Throughput : " << (operations / totalTime) << " ops/sec\n";
    std::cout << "  Latency Metrics (Microseconds):\n";
    std::cout << "    Average        : " << avgLatency << " μs\n";
    std::cout << "    p50 (Median)   : " << p50        << " μs\n";
    std::cout << "    p95 Tail       : " << p95        << " μs\n";
    std::cout << "    p99 Tail       : " << p99        << " μs\n";
    std::cout << "------------------------------------------------\n";

    exportMetricsToCSV(opName, p50, p95, p99);
    std::cout<<"________________________________________________\n\n";
}

void runFullSuite(int operations) {
    
    // ----------------------------------------------
    // 1. BENCHMARK PUT OPERATIONS (WRITE PATH)
    // ----------------------------------------------

    std::vector<double> putLatencies;
    putLatencies.reserve(operations);

    auto putStart = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < operations; ++i) {
        std::string key = "user" + std::to_string(i);
        std::string val = "data" + std::to_string(i);

        auto opStart = std::chrono::high_resolution_clock::now();
        putValue(key, val);
        auto opEnd = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> opDiff = opEnd - opStart;
        putLatencies.push_back(opDiff.count());
    }
    auto putEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> putTotal = putEnd - putStart;

    std::cout << "\n================================================\n";
    std::cout << "              velocache Benchmark           \n";
    std::cout << "================================================\n";

    printMetrics("PUT (Writes)", operations, putTotal.count(), putLatencies);

    //----------------------------------------------
    // 2. BENCHMARK GET OPERATIONS (READ PATH)
    // ----------------------------------------------

    std::vector<double> getLatencies;
    getLatencies.reserve(operations);

    auto getStart = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < operations; ++i) {
        // Look up keys we know exist to benchmark real cache hit rotation speed
        std::string key = "user" + std::to_string(i);

        auto opStart = std::chrono::high_resolution_clock::now();
        getValue(key);
        auto opEnd = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> opDiff = opEnd - opStart;
        getLatencies.push_back(opDiff.count());
    }
    auto getEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> getTotal = getEnd - getStart;

    printMetrics("GET (Reads) ", operations, getTotal.count(), getLatencies);
}

int main(){

    runFullSuite(10000);
    return 0;
}