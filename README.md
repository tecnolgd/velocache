
# VeloCache (Beta)
> A high-performance, $O(1)$ LRU Cache Engine built in C++ with persistent storage capabilities.

## Key Features:

- **Constant Time Complexity:** $O(1)$ for both `get` and `put` operations via Hash-Map and Doubly Linked List integration.       
- **Smart Hydration:** Tail-to-Head file serialization ensures cache priority is preserved across system restarts.    
- **Automatic Eviction:** Self-managing memory limit with Least Recently Used (LRU) policy.    
- **Minimal Footprint:** Zero external dependencies; optimized for embedded or sidecar use cases.

<!--   - g++ src/cache.cpp  src/storage.cpp apps/server.cpp -o build/v_server -I./include (command to build the executable)
       -./build/main.out

        building the executable for the benchmark program
        - g++ src/cache.cpp tests/benchmark.cpp -o build/v_bench
    
