#include <stdio.h>
#define MAX 10000 // 最大ノード数
#define NIL -1    // 存在しないノードを示す定義

// ノードの構造体
struct Node {
    int p, left, right; // 親、左、右の子ノード
};

Node T[MAX]; // ノードの配列
int n; // ノード数

// 前順序（Preorder）でノードを表示する関数
void preParse(int u) {
    if (u == NIL) return; // ノードが存在しない場合は終了
    printf("%d ", u); // ノードを表示
    preParse(T[u].left); // 左の子ノードを処理
    preParse(T[u].right); // 右の子ノードを処理
}

// 中順序（Inorder）でノードを表示する関数
void inParse(int u) {
    if (u == NIL) return; // ノードが存在しない場合は終了
    inParse(T[u].left); // 左の子ノードを処理
    printf("%d ", u); // ノードを表示
    inParse(T[u].right); // 右の子ノードを処理
}

// 後順序（Postorder）でノードを表示する関数
void postParse(int u) {
    if (u == NIL) return; // ノードが存在しない場合は終了
    postParse(T[u].left); // 左の子ノードを処理
    postParse(T[u].right); // 右の子ノードを処理
    printf("%d ", u); // ノードを表示
}

// メイン関数
int main() {
    int v, l, r, root = 0; // ノードの値、左、右、ルート
    scanf("%d", &n); // ノード数を入力

    // ノードの親を初期化
    for (int i = 0; i < n; i++) {
        T[i].p = NIL; // 親ノードをNILに設定
    }

    // ノードの左と右を設定
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &l, &r); // ノードの値と子ノードを入力
        T[v].left = l; // 左の子ノードを設定
        T[v].right = r; // 右の子ノードを設定
        if (l != NIL) T[l].p = v; // 左の子ノードの親を設定
        if (r != NIL) T[r].p = v; // 右の子ノードの親を設定
    }

    // ルートノードを見つける
    for (int i = 0; i < n; i++) {
        if (T[i].p == NIL) root = i; // 親がNILのノードをルートとする
    }

    // 各順序でノードを表示
    printf("Preorder\n");
    preParse(root);
    printf("\n");

    printf("Inorder\n");
    inParse(root);
    printf("\n");

    printf("Postorder\n");
    postParse(root);
    printf("\n");

    return 0; // プログラムを終了
}
