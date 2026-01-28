#include <iostream>
using namespace std;

class MARGE{
    
    private:
            int Left, Right, Mid;
     public:
           void margeSort (int arr[], int Left, int Right);
           void marge (int arr[], int Left, int Mid, int Right);
           void printSolve (int arr[], int n);
};

void MARGE :: margeSort (int arr[], int Left, int Right){

      if(Left < Right){
        
        int Mid = Left + (Right - Left) / 2;

          margeSort(arr, Left, Mid);
          margeSort(arr, Mid + 1, Right);

          marge(arr, Left, Mid, Right);

      }
}

void MARGE :: marge (int arr[], int Left, int Mid, int Right){

    int n1 =  Mid - Left + 1;
    int n2 =  Right - Mid;

    int arrb[n1];
    int arrc[n2];

    for (int i = 0; i < n1; i++)
    {
        arrb[i] = arr[Left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        arrc[j] = arr[Mid + 1 + j];
    }
       
    int i = 0;
    int j = 0;
    int k = Left;

    while (i < n1 && j < n2)
    {
        if(arrb[i] <= arrc[j]){
            arr[k] = arrb[i];
            i++;
            k++;
        }
        else{
            arr[k] = arrc[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = arrb[i];
        i++;
        k++;        
    }
   
    while (j < n2)
    {
        arr[k] = arrc[j];
        j++;
        k++;        
    }    

}

void MARGE :: printSolve(int arr[], int n){
    for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
    cout << endl;
}

int main(){
    MARGE solve;
    int n, i, j, k, l, m, r;

    cout<< "Enter the number will be in the array : ";
    cin >> n;

    l = 0;
    r = n - 1;

    int arr[n];

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<< "\n";
   
    cout<< "Unsoted: ";
    solve.printSolve(arr,n);

    solve.margeSort(arr, l, r);

    cout<< "Sorted: ";
    solve.printSolve(arr,n);

    return 0;
}
