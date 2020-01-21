#include <iostream> 
#include "space.h"
using namespace std;

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge (int a[], int si, int mid, int ei) {
    int i = si;
    int j = mid + 1;
    int size = ei- si + 1;
    int *arr = new int[size];
    int  k = 0;

    while (i <= mid && j <= ei) {
        if (a[i] < a[j]) {
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k] = a[j];
            j++;
        }
        k++;
    }

    if (i <= mid) {
        while (i != mid) {
            arr[k] = a[i];
            k++;
            i++;
        }
    }
    if (j <= ei) {
        while (j != ei) {
            arr[k] = a[j];
            k++;
            j++;
        }
    } 
    //now copy back all elements to original array
    k=0;
    for(int i = si; i <=ei; i++) {
        a[i] = arr[k];
        k++;
    }
}

void mergeSortHelper (int arr[], int si, int ei) {

    if (si <= ei) {
        return;
    }

    int mid = (si + ei) / 2;
    int lsi = si;
    int lei = mid;
    int rsi = mid + 1;
    int rei = ei;
    
    // Call reccursion on left part and right part 
    // assuming that rec will do its work
    mergeSortHelper (arr, lsi, lei);
    mergeSortHelper (arr, rsi, rei);

    // Now merge the two arrays calling the merge function
    merge(arr, si, mid, ei);

}

void mergeSort (int arr[], int size) {
    mergeSortHelper (arr, 0, size - 1);
}

void insertionSort (int arr[], int n) {
    int i, j, key, count = 0;
    cout <<"Approx space used: " << spaceCalc(4) <<endl;
    for (i = 1; i < n; i++) {
        j = i - 1;
        key = arr[i];
        count++;

        while(j >= 0 && key < arr[j]) {
            swap (&arr[j], &arr[j+1]);
            j--;
            count++;
        }
    }
    cout << "Avg RunTime: " << count;
}

void bubbleSort (int arr[], int n) {
    //cout << "\n" << sizeof(arr);
    //8 bytes as the pointer points to 1st element
    int i, j, count = 0;
    cout <<"Approx space used: " << spaceCalc(3) <<endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap (&arr[j], &arr[j + 1]);
            }
            count++;
        }
        count++;
    }
    cout << "Avg RunTime: " << count;
}

void selectionSort (int arr[], int n) {
    int i, j , minIdx, count = 0;
    cout <<"Approx space used: " << spaceCalc(4) <<endl;
    for(i = 0; i < n-1; i++) {
        minIdx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
            count++;
        }
        count++;
        //As minIndex is found now swap
        swap (&arr[i], &arr[minIdx]);
    }
    cout << "Avg RunTime: " << count;
}

void printArray (int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " " ;
    }
}

int main() {/*
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
*/
    int n;
    cout << "Insertion Sort Analysis: " << endl;
    for (int i = 10; i < 100; i*=10) {
        n = i;
        int *arr = new int[i];
        for(int j = 0 ; j < n; j++) {
            arr[j] = n - j;
        }

        printArray (arr, n);
        cout << "\n";
        cout << "For Size: " << i << endl; 
        mergeSort(arr, n);
        //selectionSort (arr, i);
        //bubbleSort (arr, n);
        //insertionSort (arr, n);
        //cout << "\nArray after sorting: "<< endl;
        printArray (arr, n);
        delete [] arr;
    }
    //delete [] arr;
}
