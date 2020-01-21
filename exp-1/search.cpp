#include <iostream>
using namespace std;

int searchX(int A[], int x, int size) {
    int count = 0;
    int i;
    
    for(i = 0; i < size; i++) {
        if(A[i] == x) {
            cout << "Avg RunTime: " << count << endl;
            return i;
        }
        count++;
    }
    cout << "Avg RunTime: " << count << endl;
    if(i == size) {
        return -1;
    }
}

int binarySearch(int A[], int x, int size) {
    int count = 0;
    int si = 0, ei = size - 1;
    int mid = (si + ei) / 2;

    while(si < ei) {
        int mid = si + (ei - si) / 2;

        if (x == A[mid]) {
            cout << "Avg RunTime: " << count << endl;
            return mid;
        }
        if (x < A[mid]) {
            ei = mid - 1;
        }
        else {
            si = mid + 1;
        }
        count++;
    }
    cout << "Avg RunTime: " << count << endl;
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int x;
    cout << "Element to be searched: ";
    cin >> x;

    int index = searchX(arr, x, n);
    //int index = binarySearch(arr, x, n);

    if(index == -1) {
        cout << "Element NOT found" <<endl;
    }
    else {
        cout << "Element found at: " << index << "th index" << endl;
    }

    return 0;
}
