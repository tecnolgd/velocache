#include <iostream>

struct Node {
    std::string key;
    std::string value;
    Node* prev;
    Node* next;
};

int main(){
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->value = "10";
    second->value = "20";
    third->value = "30";

    first->next = third;
    first->prev = second;
    second->prev = nullptr;
    second->next = first;
    third->prev = first;
    third->next = nullptr;

    std::cout<<"First node data: "<<third->prev->prev->value<<std::endl;
    std::cout<<"Second node data: "<<first->next->value<<std::endl;
    std::cout<<" third node data: "<<third->prev->prev->value<<std::endl;

    return 0;
}
