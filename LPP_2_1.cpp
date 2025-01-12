#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int arr[], int n) {
    int gaps[20];
    int numGaps = 0;
    int k = 0;

    while (true) {
        int gap = (k % 2 == 0) ? (9 * (pow(2, k) - pow(2, k / 2)) + 1) : (8 * pow(2, k) - 6 * pow(2, (k + 1) / 2) + 1);
        if (gap >= n) break;
        gaps[numGaps++] = gap;
        k++;
    }

    // Reverse gaps array
    for (int i = 0; i < numGaps / 2; i++) {
        swap(gaps[i], gaps[numGaps - 1 - i]);
    }

    for (int gapIndex = 0; gapIndex < numGaps; gapIndex++) {
        int gap = gaps[gapIndex];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        printArray(arr, n);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[500];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printArray(arr, n);
    shellSort(arr, n);

    return 0;
}
