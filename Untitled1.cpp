#include <iostream>
using namespace std;

int recursive(int Arr[], int n) {

    if (n == 0) {
        return Arr[n];
    } else {
        int max = recursive(Arr, n-1);
        if (Arr[n] > max) {
            return Arr[n];
        } else {
            return max;
        }
    }
}

int divide_conquer(int Arr[], int n, int r , int l){

	if(r== l){
		return Arr[l];
	}else{
		int mid = (l+r)/2;
		int x =divide_conquer(Arr,n,mid,l);
		int y = divide_conquer(Arr,n,r,mid+1);
		if(x > y){
		   return x;	
		}else{
		    return y;	
		}	
	}
}

int main() {
    int n = 7;
    int Arr[7] = {34, 3, 47, 91, 32, 0,101};
    int r = recursive(Arr, n-1); 
    int rr = divide_conquer(Arr, n-1 , n-1,0);
    cout << rr << endl;
    cout << r << endl;
    
    return 0;
}

