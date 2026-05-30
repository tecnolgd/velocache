
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <sys/stat.h> //for checking/creating directories
#if defined(_WIN32)
#include <direct.h>   // Required for _mkdir on Windows platforms
#endif

#include "../include/cache.hpp"

void exportMetricsToCSV(const std::string& opName, double p50, double p95, double p99) {
    const std::string dirPath = "assets";
    const std::string filePath = dirPath + "/benchmarks_log.csv";

    // 1. Ensure the assets/ directory exists safely across operating systems
#if defined(_WIN32)
    _mkdir(dirPath.c_str());
#else
    mkdir(dirPath.c_str(), 0777);
#endif

    // 2. Check if file exists to determine if we need to write the CSV header
    std::ifstream checkFile(filePath);
    bool fileExists = checkFile.good();
    checkFile.close();

    // 3. Open file in append mode so consecutive suite runs don't overwrite history
    std::ofstream csvFile(filePath, std::ios::app);
    if (!csvFile.is_open()) {
        std::cerr << "[-] Error: Could not open or create " << filePath << std::endl;
        return;
    }

    // "operation" column to differentiate between PUT and GET runs
    if (!fileExists) {
        csvFile << "timestamp,operation,p50_latency_us,p95_latency_us,p99_latency_us\n";
    }

    // 5. Generate a current ISO 8601 UTC timestamp
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&in_time_t), "%Y-%m-%dT%H:%M:%SZ");
    std::string timestamp = ss.str();

    // 6. Append the metrics row neatly with the operation name
    csvFile << timestamp << "," 
            << opName << ","
            << std::fixed << std::setprecision(4) << p50 << ","
            << p95 << ","
            << p99 << "\n";

    csvFile.close();
    std::cout << "[*] " << opName << " metrics successfully exported to " << filePath << std::endl;
}