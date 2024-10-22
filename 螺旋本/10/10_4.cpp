#include <cstdio>
#include <algorithm>

#define MAX 10000
#define INFTY (1 << 30)

int H = 0;          // ヒープのサイズ
int A[MAX + 1];     // ヒープを格納する配列

// 最大値を抽出する関数
int extract() {
    int maxv;
    if (H < 1) return -INFTY;  // ヒープが空の場合
    maxv = A[1];               // ルートにある最大値
    A[1] = A[H--];             // ヒープの最後の要素をルートに移動
    maxHeapify(1);             // ヒープの構造を維持
    return maxv;               // 最大値を返す
}

// ヒープを再構成する関数
void maxHeapify(int i) {
    int l = 2 * i;           // 左の子
    int r = 2 * i + 1;       // 右の子
    int largest;

    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;

    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest != i) {
        std::swap(A[i], A[largest]);  // 最大の子と入れ替え
        maxHeapify(largest);          // 再帰的に呼び出し
    }
}

// キーの値を増加させる関数
void increaseKey(int i, int key) {
    if (key < A[i]) return;  // 増加しない場合は何もしない
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i]) {
        std::swap(A[i], A[i / 2]);  // 親と入れ替え
        i = i / 2;                  // 親へ上がる
    }
}

// キーを挿入する関数
void insert(int key) {
    H++;              // ヒープサイズを増やす
    A[H] = -INFTY;    // 負の無限大で初期化
    increaseKey(H, key);  // キーの値を設定
}

int main() {
    char com[10];
    int key;

    while (true) {
        scanf("%s", com);
        if (com[0] == 'e' && com[1] == 'n') break;  // "end" で終了
        if (com[0] == 'i') {  // "insert" コマンド
            scanf("%d", &key);
            insert(key);
        } else if (com[0] == 'e') {  // "extract" コマンド
            printf("%d\n", extract());
        }
    }

    return 0;
}
