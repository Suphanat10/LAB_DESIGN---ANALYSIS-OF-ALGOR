#include <stdio.h>

int v[] ={12 ,5 ,4, 2};
int w[] = {8 ,7 ,4 ,2};
int k = 18;
int max_v ;


void print_sol(int x[], int n) {
   int w_ =0;
   int v_ = 0;
   
   for(int i = 0 ; i <= n ; i++){
   	if(x[i] == 1){
   		v_+=v[i-1];
   		w_ += w[i -1];
	   }
   }
   
   if( w_ <= k  &&  v_ > max_v){
       max_v = v_;
   }

}

void subset1(int x[], int l, int r) {
    if (l == r) {
        print_sol(x, r);
    } else {
        x[l + 1] = 1;
        subset1(x, l + 1, r);
        x[l + 1] = 0;
        subset1(x, l + 1, r);
    }
}


int main() {
    int n = 4; 
    int x[n + 1];	 

   subset1(x, 0, n);
    printf("%d ",max_v );

    return 0;
}

