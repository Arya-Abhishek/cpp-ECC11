#include <iostream>
using namespace std;
#include "stackClass.h"

int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.pop() <<endl;

    cout << "Size:" << s.getsize() << endl;

    cout << s.topElement() << endl;
    cout << "Size:" << s.getsize() << endl;
    cout << s.pop() << endl;
    cout << "Size:" << s.getsize() << endl;

}