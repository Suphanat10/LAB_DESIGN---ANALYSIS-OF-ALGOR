#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 
#include <iomanip> 


using namespace std;

int QuickSelect(int Arr[], int left, int right, int k) {
    int pivot = Arr[right]; 
    int partitionIndex = left;


    for (int i = left; i < right; ++i) {
        if (Arr[i] >= pivot) {
            swap(Arr[i], Arr[partitionIndex]);
            partitionIndex++;
        }
    }

    
    swap(Arr[partitionIndex], Arr[right]);

  
    if (partitionIndex == k - 1) {
        return Arr[partitionIndex];
    } else if (partitionIndex > k - 1) {
        return QuickSelect(Arr, left, partitionIndex - 1, k);
    } else {
        return QuickSelect(Arr, partitionIndex + 1, right, k);
    }
}


double AverageOfTopK(int Arr[], int n, int k) {
   
    QuickSelect(Arr, 0, n - 1, k);

   
    int sum = accumulate(Arr, Arr + k, 0);
    return static_cast<double>(sum) / k;
}

int main() {
    int n, k;
    int Arr[100];

   
    cin >> n;
    cin >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> Arr[i];
    }
    
    



    
    

    
    double result = AverageOfTopK(Arr, n, k);
     cout << fixed << setprecision(2); 
     cout<< result << endl;


    return 0;
}

