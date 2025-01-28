#include <stdio.h>

int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4; 
int n = sizeof(arr) / sizeof(arr[0]); 


int partition(int l, int r) {
    int pivot = arr[r]; 
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }


    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

  
    printf("Partitioned Array: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    return i + 1; 
}


int quickSelect(int low, int high, int k) {
    if (low == high)
        return arr[low]; 

    int p = partition(low, high);

    if (p == k - 1)
        return arr[p];
    
    else if (p > k - 1)
        return quickSelect(low, p - 1, k);
    else {
        return quickSelect(p + 1, high, k);
    }
}

 
int main() {
    printf("K-th smallest element: %d\n", quickSelect(0, n - 1, k));
    return 0;
}

