#include <iostream>
#include "node.h"
using namespace std;

node* insertNode(node *head, node *tail) {
    //cout << "head in func: " << &head << endl;

    int data;
    cout << "Enter data:";
    cin >> data;
    while (data != -1) {

        node *newNode = new node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Enter data:";
        cin >> data;
    }
    return head;
}

void deleteNode(node *head, int num) {
    //number passed is to be deleted 

    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }

    node *temp = head;

    if (head->data == num) {
        temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    while (temp != NULL) {
        if (temp->next->data == num) {
            break;
        }
        temp = temp -> next;
    }

    node *del = temp -> next;
    temp -> next = del -> next;
    delete del;

}

void printLL(node *head) {
    if (head == NULL) {
        return;
    }
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}


int main() {
    node *head = NULL, *tail = NULL;
    int num;

    cout << "head in main: " << &head << endl;

    head = insertNode(head, tail);
    cout << "head in main: " << &head << endl;

    printLL(head);

    cout << "Enter the no. to be deleted" << endl;
    cin >> num;
    deleteNode(head, num);

    printLL(head);
}






