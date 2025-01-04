#include <iostream>
#include <algorithm>
// #include <climits>

using namespace std;

int binarySearch(int Arr[], int n, int k, int left, int right, int min_) {

    if(left > right){
         if(min_ == INT_MAX){
            return -1;
         } else {
            return min_;
         }
    }

    int sum = Arr[left] + Arr[right];

    if(sum == k){
        int Arr_sum_min = Arr[right] - Arr[left];
        min_ = min(min_, Arr_sum_min);
        return binarySearch(Arr, n, k, left + 1, right - 1, min_); 
    } else if(sum < k){
        left++;
        return binarySearch(Arr, n, k , left, right, min_);
    } else {
        right--;
        return binarySearch(Arr, n, k , left, right, min_);
    }

}

int main() {
    int n, k;
    cin >> n >> k;
    int Arr[100];

    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }

    sort(Arr, Arr + n);

    int left = 0;
    int right = n - 1;
    int min_ = INT_MAX; 

    int result = binarySearch(Arr, n, k, left, right, min_);

    if (result == -1) {
        cout << "Hello" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}