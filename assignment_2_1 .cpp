#include <iostream>
using namespace std;

int binary_search(int A[], int k, int r, int l)
{
   
	 int mid = l + ((k - A[l]) * (r - l))/( A[r] - A[l]);
      cout<<mid<<" ";
	

    if (l>r)
    {
        return -1;
    }

    if (A[mid] == k)
    {
    	 
        return mid;
    }

   else if  (A[mid] < k) 
    {
        l = mid + 1;
        binary_search(A, k, r, l);
        
    }
    else 
    {
        r = mid - 1;
        binary_search(A, k, r, l);
    }
}

int main()
{
    int n;
    int k;
    cin >> n >> k;

    int Arr[100];
    for (int i = 0;i < n; i++)
    {
        cin >> Arr[i];
    }

    int r = (n - 1);
    int l = 0;

    binary_search(Arr, k, r, l);
}