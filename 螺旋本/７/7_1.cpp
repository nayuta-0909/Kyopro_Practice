#include <iostream>
using namespace std;
#define MAX 50000000000000
#define SENTINEL 20000000000000000

// 左半分と右半分の一時的な配列を宣言
int L[MAX/2+2], R[MAX/2+2];
int cnt; // マージの回数をカウントする変数

// マージ関数: 配列の2つの部分をマージしてソートする
void merge(int A[], int n, int left, int mid, int right){
    int n1 = mid - left; // 左部分の要素数
    int n2 = right - mid; // 右部分の要素数

    // 左部分を一時的な配列Lにコピー
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    // 右部分を一時的な配列Rにコピー
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];

    // 番兵として非常に大きな値を設定
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;

    // 左部分と右部分をマージしながら元の配列Aに格納
    for (int k = left; k < right; k++){
        cnt++; // 比較回数をカウント
        if (L[i] <= R[j]){
            A[k] = L[i++]; // Lの要素をAにコピー
        } else {
            A[k] = R[j++]; // Rの要素をAにコピー
        }
    }
}

// マージソート関数: 再帰的に配列を分割し、ソートする
void mergeSort(int A[], int n, int left, int right){
    if (left + 1 < right){ // 要素が1つになるまで分割する
        int mid = (left + right) / 2; // 中間地点を計算
        // 左部分を再帰的にソート
        mergeSort(A, n, left, mid);
        // 右部分を再帰的にソート
        mergeSort(A, n, mid, right);
        // 分割された部分をマージ
        merge(A, n, left, mid, right);
    }
}

int main(){
    // メイン関数（テスト用のコードを追加する必要があります）
    return 0;
}
