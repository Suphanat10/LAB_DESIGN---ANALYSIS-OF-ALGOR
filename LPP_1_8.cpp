#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n; 
   int A[1000];  
   for (int i = 0; i < n; i++) {
       cin >> A[i]; 
   }

   int max_sum = A[0];  
   
   for (int i = 0; i < n; i++) {
       for (int j = i; j < n; j++) {
           int current_sum = 0;
           for (int k = i; k <= j; k++) {
               current_sum += A[k];  
           }
           max_sum = max(max_sum, current_sum); 
       }
   }

   cout << max_sum << endl;

   return 0;
}