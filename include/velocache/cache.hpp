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

Node* head = nullptr;
Node* tail = nullptr;

std::string getValue(std::string key);
std::string putValue(std::string key, std::string value);
void attachToHead(Node* &n);
void disconnect(Node* n);
void printData();

#endif