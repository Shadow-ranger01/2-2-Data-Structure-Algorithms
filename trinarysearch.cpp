///3. Trinary Search in cpp

#include <iostream>
using namespace std;

int ternarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {

        // Split into 3 parts
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Check mid1
        if (arr[mid1] == key)
            return mid1;

        // Check mid2
        if (arr[mid2] == key)
            return mid2;

        // If key is smaller than mid1 → search left part
        if (key < arr[mid1])
            right = mid1 - 1;

        // If key is greater than mid2 → search right part
        else if (key > arr[mid2])
            left = mid2 + 1;

        // Otherwise search the middle part (between mid1 and mid2)
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1; // Not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int result = ternarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found in the array." << endl;

    return 0;
}
