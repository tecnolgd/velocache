#include <iostream>

struct Node {
    std::string key;
    std::string value;
    Node* prev = nullptr;
    Node* next = nullptr;
};