#include <iostream>
using namespace std;


int divide_and_conquer(int arr[], int target, int left, int right) {
    if (left == right) {
        return arr[left] == target ? 1 : 0;
    }


    int mid = left + (right - left) / 2;
    int left_count = divide_and_conquer(arr, target, left, mid);
    int right_count = divide_and_conquer(arr, target, mid + 1, right);

    return left_count + right_count;
}

int count_target(int arr[], int n, int target) {
    int count = divide_and_conquer(arr, target, 0, n - 1);
    return count > 0 ? count : -1;
}

int main() {
   
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

   
    int result = count_target(arr, n, k);
    cout << result << endl;

    return 0;
}
