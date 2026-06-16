## velocache Usage Info

> To start using velocache, complete the [installation and build procedures](../../README.md#installation--build).
>(Tip: Keep assets/cache_data.txt file open side-by -side to see the cache behavior and LRU logic in real-time)

### The Application flow
> (**Note:** A do-while loop is used for multiple sessions with user control to end the session)

1. At the start of the excecution of the application, the **server** (src/server.cpp) will be already loaded with data from the previous session(if any).    
    - This data is loaded from a file called **cache_data.txt** located in the **assets/** folder. (This happens once every new session)   
    - For in-depth details on how this cache server is implemented, check [LRU eviction](https://www.geeksforgeeks.org/dsa/lru-cache-implementation-using-double-linked-lists/).<!--[architecture]() :insert link to hash-map and dll based storage & retrieval of data info in future versions-->

2. The application would ask for number of nodes to be stored in the cache.
    - As defined in the **include/cache.hpp**, the maximum number of data elements is restricted to **3**.

        ```txt
        velocache >>>>
        LOG: Cache loaded from the file

        Operations supported
        1. Data storage
        2. Data retrieval
        3. Cache display
        4. Save Cache
        5. Exit
        Select an option (1-5): 
        ```

3. Enter the key and data pairs as prompted by the application. By default, the application takes **strings as both key and value** unless modified by the user for their needs and requirements.
    - If the key already exists in the cache, velocache will display a warning and ask whether to overwrite the existing value.

        - Skipping existing value

            ```txt
            --- User 1 ---
            Enter key: 111
            Warning: key '111' already exists. Overwrite? (y/n): n
            Skipped duplicate key: 111
            ```
        - Overwriting existing value

            ```txt
            --- User 2 ---
            Enter key: qqq
            Warning: key 'qqq' already exists. Overwrite? (y/n): y
            Overwriting existing value for key: qqq
            Enter value: 333
            ```

    - While choosing option **3**, the current cache would be displayed on the console with the recently used element (either **recently** added or retrieved since retrieval changes the location of the key-value pair) labelled for user interpretation.

        ```txt
        Select an option (1-5): 3

        Key      |  Value
        * user_k     12345
        * user_n     1211
        * 1     1 [ Recent ]
        ```

    - If the cache is already full (i.e if current capacity of the cache = Max. capacity of the cache), then **eviction of the oldest** data takes place. (Check [Algorithmic Flow](architecture.md#2-algorithmic-flow--complexity) for more details)
    - A log message regarding the data that is to be evicted would be displayed on the console and updated cache would be displayed instantly.
        ```txt
        Select an option (1-5): 1
        Enter number of users: 1

        --- User 1 ---
        Enter key: user_n
        Enter value: 1211
        ALERT: Capacity reached. Evicting: abc#indicates the cache is already full
        ```

4. The retrieval of value using the key can be achieved from **entering the key** on the console for the respective prompt.
    - If the key exists, then the corresponding value is displayed on the console with the cache order also getting updated since the retrieval made the data the recently accessed data from the cache.
        ```txt
        Select an option (1-5): 2

        Enter key: user_n
        Getting data: 1211
        ```

    - If the key doesn't exists, then a message describing the absence of the key would be displayed on the console.
        ```txt
        Select an option (1-5): 2

        Enter key: abc
        Getting data: Value NOT found!
        ```

5. Saving the Cache can be done explicitly by the user, or the Cache gets saved implicitly when the application terminates normally via option **5** (Exit). The server also persists cache data when it receives supported termination signals such as **Ctrl+C** (`SIGINT`) and `SIGTERM`.

    ```txt
    Select an option (1-5): 4
    Saving cache to disk...

    Cache saved successfully.
    ```

## The Benchmark tool

### Overview
The velocache benchmark suite is designed to measure and track performance metrics across different cache operations. It provides comprehensive latency analysis and throughput measurements with automated CSV logging for trend analysis.

### Running the Benchmark

1. Follow the build instructions for the benchmark tool and run the build file:
   ```bash
   make v_bench
   ./build/v_bench
   ```
2. The program executes **10,000 iterations** for both `getValue()` and `putValue()` operations and displays real-time metrics including:
   - **Throughput:** Operations per second (ops/sec)
   - **Latency Percentiles:** p50 (median), p95, and p99 tail latencies in microseconds
   - **Average Latency:** Mean latency across all operations

### CSV Logging & Data Persistence
Benchmark results are automatically logged to **`assets/benchmarks_log.csv`** with the following fields:
- **timestamp:** ISO 8601 formatted timestamp of the benchmark run
- **operation:** Operation type (PUT Writes or GET Reads)
- **p50_latency_us:** Median latency in microseconds
- **p95_latency_us:** 95th percentile latency in microseconds
- **p99_latency_us:** 99th percentile latency in microseconds

This allows for historical performance tracking and trend analysis across multiple benchmark runs.

### Example Output
```
================================================
              velocache Benchmark           
================================================
  PUT (Writes) Throughput : 16718 ops/sec
  Latency Metrics (Microseconds):
    Average        : 59.8157 μs
    p50 (Median)   : 4.043 μs
    p95 Tail       : 43.999 μs
    p99 Tail       : 72.112 μs
------------------------------------------------
[✓] PUT (Writes) metrics successfully exported to assets/benchmarks_log.csv
________________________________________________

  GET (Reads)  Throughput : 3.92583e+06 ops/sec
  Latency Metrics (Microseconds):
    Average        : 0.254723 μs
    p50 (Median)   : 0.12 μs
    p95 Tail       : 0.138 μs
    p99 Tail       : 0.157 μs
------------------------------------------------
[✓] GET (Reads)  metrics successfully exported to assets/benchmarks_log.csv
________________________________________________
```

## Demo GIF
- [Benchmark](../v_bench_demo.gif)
- [CSV logging](../v_csv_demo.gif)