#include <stdio.h>
#include <stdlib.h>
#define MAX 200000000
#define VMAX 10000

int main() {
    unsigned short *A, *B;
    int C[VMAX + 1];
    int n, i, j;

    // 配列のサイズを入力
    scanf("%d", &n);

    // 配列AとBのメモリを動的に確保
    A = (unsigned short *)malloc(sizeof(unsigned short) * (n + 1));
    B = (unsigned short *)malloc(sizeof(unsigned short) * (n + 1));

    // カウント配列Cを初期化（すべて0にする）
    for (i = 0; i <= VMAX; i++) C[i] = 0;

    // 配列Aに入力値を格納し、C配列に出現回数をカウント
    for (i = 0; i < n; i++) {
        scanf("%hu", &A[i + 1]); // 配列は1から始まるインデックスに格納
        C[A[i + 1]]++; // 入力値の出現回数をカウント
    }

    for(i=1;i<=VMAX;i++) {
        C[i] = C[i] + C[i-1];
    }

    for(j=1; j<=n;j++) {
        B[C[A[j]]] = A[j];
        C[A[j]] --;
    }

    
}