#include <bits/stdc++.h>
#include <algorithm>



using namespace std;

 long long int concount(int Arr[] , int n){
 	
 	if(n == 0){
 		return 0;
	 }else{
	 	int concount_v = 1;
	 	for(int i = 1 ; i < n ; i++){
	 		if(Arr[i] != Arr[i-1] +1){
	 			concount_v++;
			 }
		 }
		 
		 return concount_v;
	 }


 }


int main (){
	 int Arr[100];
	 int n;
	 cin >>n;
	 for(int i = 0 ; i < n ; i++){
	 	cin>>Arr[i];
	 }

    sort(Arr, Arr + n);
    int r = concount(Arr,n);
    cout<<r<<endl;
    
	
	return 0;
}
