#include <iostream>
using namespace std;

int main() {
   int n, sum;
   cin >> n >> sum;

   int Arr[1000];
   for (int i = 0; i < n; i++) {
       cin >> Arr[i];
   }

   bool found = false;


  for (int i = 0; i < n; i++) {
       for (int j = i + 1; j < n; j++) { 
          
           if (Arr[i] + Arr[j] == sum) {
               cout << Arr[i] << " " << Arr[j] << endl; 
               found = true; 
           }
       }
   }

   if (!found) {
       cout << -1 << endl;
   }

   return 0;
}