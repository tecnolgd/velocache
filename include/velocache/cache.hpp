//header file for src/cache.cpp

#ifndef CACHE
#define CACHE

#include <iostream>
#include <string>
#include <unordered_map>

struct Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;
};
std::string getValue(std::string key);
void attachToHead(Node* &n);
void disconnect(Node* n);
void printData();

#endif