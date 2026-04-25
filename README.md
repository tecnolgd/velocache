
<h1 style="font-size: 60px; font-family: roboto;" align= "center">velocache</h1>

<div align = "center">
<a href = "https://opensource.org/licenses/MIT"><img src = "https://img.shields.io/badge/License-MIT-green.svg" alt = "MIT License"></a>
<img src = "https://img.shields.io/badge/g++-13.3.0%2B-blue" alt = "g++ 13.3.0+">
<img src = "https://img.shields.io/badge/interface-CLI-white" alt = "Interface: CLI">
<a href = "https://github.com/tecnolgd/velocache/releases"><img src = "https://img.shields.io/badge/Release-v0.1.0_(beta)-orange" alt = "Release: v0.1.0-beta"></a>
<a href = "#documentation"><img src = "https://img.shields.io/badge/docs-available-blue" alt = "Docs"></a>
</div>
<hr>

> A high-performance, $O(1)$ LRU Cache Server built in C++ with persistent storage capabilities.
---
![velocache_demo](assets/v_demo.gif)

## Key Features:

- **Constant Time Complexity:** $O(1)$ for both `get` and `put` operations via Hash-Map and Doubly Linked List integration.       
- **Smart Hydration:** Tail-to-Head file serialization ensures cache priority is preserved across system restarts.    
- **Automatic Eviction:** Self-managing memory limit with Least Recently Used (LRU) policy.    
- **Minimal Footprint:** Zero external dependencies; optimized for embedded or sidecar use cases.

## Performance data
Results achieved from internal benchmarking [for 10k operations involving *putValue()* module]      
- **Throughput:** ~24006 ops/sec
- **Time Complexity:** $O(1)$

## Documentation
- [Architecture](assets/docs/architecture.md)
- [Roadmap](assets/docs/roadmap.md)
- [Tool usage](assets/docs/usage.md)

## Installation & Build

>Ensure you have `g++` installed( `make` recommended). 
```bash
#clone the repo
git clone https://github.com/tecnolgd/velocache/
```
```bash
#navigate to the project directory
cd velocache
```

From the project directory, run the following commands:    

 ### Using make (recommended) 

- Build **both** the server and the benchmark tool
```bash
    make
```
or
```bash
    make all
```

- Build and run individualy      
    - **The Server**:     
    ```bash
        make v_server
    ```       
    - **The Benchmark Tool**:
    ```bash
        make v_bench
    ```
- Clean object files:
```bash
make clean
```

### Manual Build and Run
1. The Server     
- Build:      
```bash
g++ src/cache.cpp  src/storage.cpp apps/server.cpp utils/input_validation.cpp -I./include-03 -Wall -o build/v_server  
```      
- Run:      
```bash   
./build/v_server
```      

2. The Benchmark Tool     
- Build:       
```bash
g++ src/cache.cpp tests/benchmark.cpp -I./include-03 -Wall -o build/v_bench
```     
- Run:     
```bash
./build/v_bench
```
## [Contributing](CONTRIBUTING.md)

## Author & Version

- **Author:** tecnolgd  
- **Version:** v0.1.0-beta  
- **License:** [MIT License](LICENSE.md)
