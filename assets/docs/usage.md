
## velocache Usage Info

> To start using velocache, complete the [installation and build procedures](../../README.md#installation--build/).
>(Tip: Keep assets/cache_data.txt file open side-by -side to see the cache behavior and LRU logic in real-time)

### The Application flow
> (Note: A do-while loop is used for multiple sessions with user control to end the session)

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
    - The **keys cannot be repeated** i.e while entering the key, make sure that the **same key does not exists in the cache** while on the other hand, value could be repeated.
    - While choosing option **3**, the current cache would be displayed on the console with the recently used element (either **recently** added or retrieved since retrieval changes the location of the key-value pair) labelled for user interpretation.

    ```txt
    Select an option (1-5): 3

    Key      |  Value
    * user_k     12345
    * user_n     1211
    * 1     1 [ Recent ]
    ```

    - If the cache is already full (i.e if current capacity of the cache = Max. capacity of the cache), then **eviction of the oldest** data takes place. (via [LRU eviction policy]())
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

5. Saving the Cache can be done explicitly done be the user or the Cache get saved implicitely via `atexit([]() { store_cache_data(head); })` when the application terminates.

```txt
Select an option (1-5): 4
Saving cache to disk...

Cache saved successfully.
```

## The Benchmark tool
1. Follow the build instructions for the benchmark tool and run the build file.
2. The program would run until 10k iterations and display the **Average time and operations/second**.      
> Note: This benchmark is currently for the putValue() module; benchmarking for other modules would be added in the future versions.

## Demo GIF
[Demo](../v_demo.gif)