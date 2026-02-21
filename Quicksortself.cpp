#include<iostream>
#include<ctime>
#include<cstdlib> 
using namespace std;

int makePart(int arr[], int First, int Last);

void QuickSort(int arr[], int First, int Last){

    if(First <  Last){

        int j =  makePart(arr, First, Last);
           
        QuickSort(arr, First, j-1);
        QuickSort(arr, j+1, Last);

    }
}

int makePart(int arr[], int First, int Last){

    int i = First;
    int j = Last + 1;
    int pivot = arr[First];

    do
    {
        do
        {
            i++;

        } while (pivot > arr[i]);

        do
        {
            j--;

        } while (pivot < arr[j]);

        if (i < j){
            int temp =  arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    } while (i < j);
    
    arr[First] = arr[j];
    arr[j] = pivot;
    
    return j;

}

void printArr(int arr[], int n){

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main(){
  
    int n;

    cout<< "Enter the number of elements will be in the array: ";
    cin>> n;

    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    
    cout<< "\n ~~~~ The UNSORTED ARRAY ~~~~~ \n";
    printArr(arr, n);

    QuickSort(arr, 0, n-1);

    cout<< "\n  ~~~~ The SORTED ARRAY ~~~~~ \n";
    printArr(arr, n);

    return 0;
}
