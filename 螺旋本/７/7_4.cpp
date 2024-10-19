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

    // 配列Cに累積和を計算（各要素の位置を決定するため）
    for (i = 1; i <= VMAX; i++) {
        C[i] = C[i] + C[i - 1];
    }

    // 配列Bにソートされた要素を格納
    for (j = 1; j <= n; j++) {
        B[C[A[j]]] = A[j]; // 配列Aの要素をBの適切な位置に配置
        C[A[j]]--; // 同じ値があれば次の位置に配置するためにデクリメント
    }

    // ソートされた配列Bを出力
    for (i = 1; i <= n; i++) {
        if (i > 1) printf(" "); // 要素間にスペースを挿入
        printf("%d", B[i]);
    }
    printf("\n");

    // 確保したメモリを解放
    free(A);
    free(B);

    return 0;
}
