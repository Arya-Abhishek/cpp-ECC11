#include <iostream>
using namespace std;

class stack {
    int top = 0, capacity;
    int *data;

    public:

    stack() {
        capacity = 2;
        data = new int[capacity];
    }

    int getsize() {
        return top;
    }

    int topElement() {
        if (top > 0) {
            int x = data[top];
            return x;
        }
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(int x) { 
        if (top == capacity) {

            //removing size constraints
            int *newData = new int[2 * capacity];
            for (int i = 0; i < top; i++) {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            //cout << capacity << endl;
            data = newData;
            delete(newData);
            return;
        }

        data[++top] = x;
    }

    int pop() {
        if (top == 0) {
            return 0;
        }

        int x = data[top];
        top--;
        return x;
    }
};