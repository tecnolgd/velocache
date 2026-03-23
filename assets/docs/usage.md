
## VeloCache Usage Info

> To start using VeloCache, complete the [installation and build procedures](../../README.md#installation--build/).
>(Tip: Keep assets/cache_data.txt file open side-by -side to see the cache behavior and LRU logic in real-time)

### The application flow
1. At the start of the excecution of the application, the **server** (src/server.cpp) will be already loaded with data from the previous session(if any).

- This data is loaded from a file called **cache_data.txt** located in the **assets/** folder.    
- For more details on how the data is stored and manipulated, check [architecture]().<!--insert link to hash-map and dll based storage & retrieval of data-->

2. The application would ask for number of nodes to be stored in the cache.
- As defined in the **include/velocache/cache.hpp**, the maximum number of data elements is restricted to **3**. This could be modified by as per the need and interests of the user.
-  


