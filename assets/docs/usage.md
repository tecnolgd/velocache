
## VeloCache Usage Info

> To start using VeloCache, complete the [installation and build procedures](../../README.md#installation--build/).
>(Tip: Keep assets/cache_data.txt file open side-by -side to see the cache behavior and LRU logic in real-time)

### The Application flow
1. At the start of the excecution of the application, the **server** (src/server.cpp) will be already loaded with data from the previous session(if any).

- This data is loaded from a file called **cache_data.txt** located in the **assets/** folder.    
- For more details on how the data is stored and manipulated, check [architecture]().<!--insert link to hash-map and dll based storage & retrieval of data-->

2. The application would ask for number of nodes to be stored in the cache.
- As defined in the **include/velocache/cache.hpp**, the maximum number of data elements is restricted to **3**. This could be modified by as per the need and interests of the user.
<!--enter initial app prompt-->

3. Enter the key and data pairs as prompted by the application. By default, the application takes **strings as both key and value** unless modified by the user for their needs and requirements.
- The **keys cannot be repeated** i.e while entering the key, make sure that the **same key does not exists in the cache** while on the other hand, value could be repeated.
- While pressing 'Enter', the current cache would be displayed on the console with the recently used element (either **recently** added or retrieved since retrieval changes the location of the key-value pair) labelled for user interpretation.
- If the cache is already full (i.e if current capacity of the cache = Max. capacity of the cache), then **eviction of the oldest** data takes place. (via [LRU eviction policy]())
- A log message regarding the data that is to be eviceted would be displayed on the console and updated cache would be displayed instantly.
<!--enter console output which shows the alert before evicting-->

4. The retrieval of value using the key can be achieved from **entering the key** on the console for the respective prompt.
- If the key exists, then the corresponding value is displayed on the console with the cache order also getting updated since the retrieval made the data the recently accessed data from the cache.
- If the key doesn't exists, then a message describing the absence of the key would be displayed on the console.
<!--enter output of the console here for the key not found error-->

## Demo GIF
[Demo]()
