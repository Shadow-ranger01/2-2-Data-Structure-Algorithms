//sorting any type of a given data 
// this is the first class of the algorithm in the lab some of the sorting problem are 
// insertion sort, bubble sort, merge sort, quick sort, counting sort, selection sort, heap sort

// algorithm of INSERTION SORT
/*
    unsorted = 29, 59, 10, 7, 9, 12, 1 
               0    1   2  3  3  5   6

    sorted = 1, 7, 9, 10, 12, 29, 59 
    
    every postion will be cheaked when the prossecsee propagets, and the sort starts i+1 no index or the no 1 index of the array
    compare with the proivious inedx of the arry

    step 01: 29, 59, 10, 7, 9, 12, 1  [sorted in 0, 1 index]
            0,   1

    step 02: 10, 29, 59, 7, 9, 12, 1  [sorted in 0, 1, 2 index] and 10 is compared with all the privious index and moved to 0 th index
              0   1   2

    step 03: 7, 10, 29, 59, 9, 12, 1 [sorted in 0, 1, 2, 3 index] and 7 is compared with all the privious indexs and moved to the 0 th index
             0   1   2  3

    step 04: 7, 9, 10, 29, 59, 12, 1 [sorte in 0,1,2,3,4 index] and 9 is compared and moved forworted to the 1 th index
             0  1  2   3   4
         
    step 05: 7, 9, 10, 12, 29, 59, 1
    
    step 06: 1, 7, 9, 10, 12, 29, 59 [sorted all]
    

*/

#include <iostream>
using namespace std;

int main()
{

    int n , i ,j, k;

    cout<< "enter the number of elemetns in the array : "<< endl; 
    cin >> n;
    
    int arr[n];

    for (i = 0; i < n; i++)
    {
        cout << "input to the index no "<< i << " : ";
        cin >> arr[i];
    }

    cout << "\n unsorted list : ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
     
    for (int i = 1; i < n; i++) {
        int k = arr[i];   // inserted
        int j = i -1;

        // Move 
        while (j >= 0 && arr[j]>k) {
            arr[j+ 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = k;

        }    
 
        cout << "\n\n sorted list : ";
        for (i = 0; i < n; i++)
        {
            cout << arr[i] <<" ";
        }        



    return 0; 
}

