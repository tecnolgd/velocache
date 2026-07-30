//header file for src/cache.cpp

//g++ src/cache.cpp  src/storage.cpp apps/server.cpp -o build/v_server -I./include (command to build the executable)
//./build/main.out

#ifndef CACHE
#define CACHE

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

class Cache{

    private:

    struct Node {
        std::string key;
        std::string value;
        Node* prev;
        Node* next;
    };
    std::unordered_map<std::string, Node*> cacheMap;

    std::size_t max_size = 0; //junk value will never be present in max_size

    //const int MAX = 3; //max nodes capable of being present at a time

    Node* head = nullptr; //inline --> to make sure all instances of 'head' and 'tail' are treated as one
    Node* tail = nullptr;

    public:

    //constructor modern way
    //helps in assigning the max_size the moment object is created
    
    Cache(std::size_t maxCapacity) : max_size(maxCapacity){}

    //destructor
    ~Cache(){
        Node* current = head;
        while (current) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        cacheMap.clear();
    }

    std::string getValue(const std::string& key);
    void putValue(const std::string& key, const std::string& value);
    void attachToHead(Node* &n);
    void disconnect(Node* n);

    void store_cache_data(); //store cache data (persistent data)
    void load_from_file();
    void clear_cache(); //to clear the entire cache
    bool contains(const std::string& key) const;

};
#endif