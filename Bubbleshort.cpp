//1. Binary Search in CPP


#include <iostream>
using namespace std;

int main() {
    int arr[5], n = 5;

    // Taking input
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {          
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {        
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
