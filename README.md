
# VeloCache (Beta)
> A high-performance, $O(1)$ LRU Cache Engine built in C++ with persistent storage capabilities.

## Key Features:

- **Constant Time Complexity:** $O(1)$ for both `get` and `put` operations via Hash-Map and Doubly Linked List integration.       
- **Smart Hydration:** Tail-to-Head file serialization ensures cache priority is preserved across system restarts.    
- **Automatic Eviction:** Self-managing memory limit with Least Recently Used (LRU) policy.    
- **Minimal Footprint:** Zero external dependencies; optimized for embedded or sidecar use cases.

## Performance data
Results achieved from internal benchmarking [for 10k operations]      
- **Throughput:** ~24006 ops/sec
- **Time Complexity:** $O(1)$

## Documentation
- [Architecture](assets/docs/architecture.md)
- [Roadmap](assets/docs/roadmap.md)
- [Tool usage](assets/docs/usage.md)

## Installation & Build
Ensure you have `g++` installed( `make` recommended). From the project directory, run the following commands:    

 ### Using make (recommended)         
- Build and run **the server**:     
```bash
make v_server
```

- Build and run **the benchmark tool**:
```bash
make v_bench
```
- Clean .o files:
```bash
make clean
```

### Manual Build and Run
1. The Server     
- Build:      
```bash
g++ src/cache.cpp  src/storage.cpp apps/server.cpp -I./include -03 -o build/v_server  
```      
- Run:      
```bash   
./build/v_server
```      

2. The Benchmark Tool     
- Build:       
```bash
g++ src/cache.cpp tests/benchmark.cpp -I./include -03 -o build/v_bench
```     
- Run:     
```bash
./build/v_bench
```

## Author & Version

- **Author:** tecnolgd  
- **Version:** v0.1.0-beta  
- **License:** [MIT License](LICENSE.md)