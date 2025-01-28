#include <iostream>
#include <algorithm>

using namespace std;

//int medianOfThree(int arr[], int l, int r) {
//    int center = (l + r) / 2;
//
//
//    if (arr[l] > arr[center]) {
//        swap(arr[l], arr[center]);
//    }
//    if (arr[l] > arr[r]) {
//        swap(arr[l], arr[r]);
//    }
//    if (arr[center] > arr[r]) { 
//        swap(arr[center], arr[r]);
//    }
//
//
//    swap(arr[center], arr[r - 1]);
//    return arr[r - 1];
//}

int medianOfThree(int arr[], int l, int r) {
    int center = (l + r) / 2;

    // Arrange elements such that arr[l] <= arr[center] <= arr[r]
    if (arr[l] > arr[center]) {
        swap(arr[l], arr[center]);
    }
    if (arr[l] > arr[r]) {
        swap(arr[l], arr[r]);
    }
    if (arr[center] > arr[r]) {
        swap(arr[center], arr[r]);
    }

    // Move pivot to r-1 and return its value
    swap(arr[center], arr[r - 1]);
    return arr[r - 1];
}

int partition(int arr[], int l, int r) {
    int pivot = medianOfThree(arr, l, r); // Determine pivot using medianOfThree
    int i = l + 1;  // Left pointer starts after the leftmost element
    int j = r - 2;  // Right pointer starts before the pivot

    while (true) {
        while (arr[i] < pivot) ++i; // Move i to the right
        while (arr[j] > pivot) --j; // Move j to the left
        if (i >= j) break;         // Pointers crossed, partition is complete
        swap(arr[i], arr[j]);      // Swap elements at i and j
    }

    // Place the pivot in its correct position
    swap(arr[i], arr[r - 1]);
    return i; // Return the final position of the pivot
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pivotIndex = partition(arr, l, r);
        cout << pivotIndex << endl;
        quickSort(arr, l, pivotIndex - 1); // Sort left partition
        quickSort(arr, pivotIndex + 1, r); // Sort right partition
    }
}

int main() {
    int n;
    cin >> n;

    int arr[500];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

