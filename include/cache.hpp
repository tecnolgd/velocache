//header file for src/cache.cpp

//g++ src/cache.cpp  src/storage.cpp apps/server.cpp -o build/v_server -I./include (command to build the executable)
//./build/main.out

#ifndef CACHE
#define CACHE

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

struct Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;
};

inline std::unordered_map<std::string, Node*> cacheMap;
const int MAX = 3; //max nodes capable of being present at a time

inline Node* head = nullptr; //inline --> to make sure all instances of 'head' and 'tail' are treated as one
inline Node* tail = nullptr;

std::string getValue(std::string key);
void putValue(std::string key, std::string value);
void attachToHead(Node* &n);
void disconnect(Node* n);

#endif