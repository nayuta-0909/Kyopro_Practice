#include <stdio.h>

int main(){
    int n;
    int q;
    int A[100];
    int B[100];
    int count=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&q);
    for(int j=0;j<q;j++){
        scanf("%d",&B[j]);
    }

    for(int i=0;i<n;i++){
        for(int j = 0;j<q;j++){
            if(A[i]==B[j]){
                count += 1;
            }
        }
    }

    printf("%d",count);
}