//selection swap mal ta iqtu tera ache....
//in other words dhoro tokta maro T

#include <stdio.h>

void selectionSort(int A[], int n) {

    //ai 'i' hala er akta e kaj choto or 0th index theka suru hobe ar update hoithe thakve 1-2-3-4...
    for (int i = 0; i < n-1; i++) {
        int chotoindex = i;

    //ai 'j' hala cheak mare current i er thake choto kau ache naki loop koiray     
        for (int j = i+1; j < n; j++) {

            //ai if hala help koray cheak korar jonno...
            //if 'jodi' A[j] choto hoy A[chotoindex] thake tahole sala change marbe
            if (A[j] < A[chotoindex]) {
                chotoindex = j;
            }
        }
        
        // ari sala ato dekhi swap....
        int temp = A[i];
        A[i] = A[chotoindex];
        A[chotoindex] = temp;
    }
}

int main() {
    int n;
    
    //input runtime nisi amar iccha tai..
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];  //create array of size n

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    //mal ta kay call day..
    selectionSort(A, n);
    
    printf("Selection Sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
