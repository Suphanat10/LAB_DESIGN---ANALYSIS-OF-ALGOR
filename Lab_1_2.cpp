#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long long int count_Arr(int Arr[], int n) {
    if (n == 0) {  
        return 0;
    }

    int maxCount = 0, minCount = INT_MAX; 
    int currentCount = 1; 

    for (int i = 1; i < n; i++) { 
        if (Arr[i] == Arr[i - 1]) { 
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            minCount = min(minCount, currentCount);
            currentCount = 1; 
        }
    }


    maxCount = max(maxCount, currentCount);
    minCount = min(minCount, currentCount);

    return maxCount - minCount;
}

int main() {
    int Arr[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }

    sort(Arr, Arr + n);  
    int r = count_Arr(Arr, n);
    cout << r << endl;

    return 0;
}

