#include <iostream>
using namespace std;
#define MAX 2000000 // 最大ノード数を定義

int H, A[MAX + 1]; // Hはヒープのサイズ、Aはヒープの配列

// ノードiについて並べかえる関数
void maxHeapify(int i) {
    int r, l, largest;
    l = 2 * i; // 左の子は必ず偶数ノード
    r = 2 * i + 1; // 右の子は必ず奇数ノード

    // 左の子が存在し、左の子の値がノードiの値より大きい場合
    if (l <= H && A[l] > A[i]) largest = l; 
    else largest = i; // それ以外はノードiが最大

    // 右の子が存在し、右の子の値が現在の最大値より大きい場合
    if (r <= H && A[r] > A[largest]) largest = r;

    // largestがiでない場合、すなわちノードiが最大でない場合
    if (largest != i) {
        swap(A[i], A[largest]); // ノードiと最大ノードをスワップ
        maxHeapify(largest); // スワップされたノードに対して再帰的に最大ヒープ化を行う
    }
}

int main() {
    // ノード数の入力
    cin >> H;

    // ノード分のループ
    for (int i = 1; i <= H; i++) cin >> A[i]; // ヒープに値を入力

    // 大きい順に並び変える（最大ヒープを構築）
    for (int i = H / 2; i >= 1; i--) maxHeapify(i); // 下から上にヒープ化を行う

    // ヒープの内容を出力
    for (int i = 1; i <= H; i++) {
        cout << A[i] << " "; // ヒープの各要素を出力
    }
    cout << endl; // 改行

    return 0; // プログラム終了
}
