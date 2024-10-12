#include <stdio.h>


int main(){
    int n,A[100],q,B[100];
    int left = 0,right= n, mid=n/2;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&q);
    for(int j=0;j<q;j++){
        scanf("%d",&B[j]);
    }

    for(int i=0;i<n;i++){
        for(int j =0;j< q j++){
            if(B[q]<A[mid]){
                right = mid;
                mid = mid/2;
            }else if(B[q] > A[mid]){
                left = mid;
                mid = right/2;
            }
        }
    }

}