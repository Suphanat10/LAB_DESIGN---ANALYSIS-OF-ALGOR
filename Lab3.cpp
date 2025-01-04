#include <iostream>
using namespace std;

int countBits(int n){
	if(n == 0){
		return 0;
	}
	
	 return (n & 1) + countBits(n >> 1);
}

int main() {
   int n;
   cin >> n; 
   if (n < 0 || n > 500) {
       cout << "Invalid input. n must be between 0 and 500." << endl;
       return 1;
   }
   cout << countBits(n) << endl; 
   return 0;
}




