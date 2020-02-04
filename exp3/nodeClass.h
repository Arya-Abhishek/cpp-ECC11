#include <iostream>
class node {
    public:
    int data;
    node* next;

    node(int data){
        node *newNode = new node(data);
        newNode->next = NULL;
    }
};