#include <cstdio>
#define MAX 10000  // 最大ノード数
#define NIL -1     // 存在しないノードを示す定義

// ノードの構造体
struct Node {
    int parent, left, right; // 親、左、右の子ノード
};

Node T[MAX]; // ノードの配列
int n, D[MAX], H[MAX]; // ノード数、深さ、及び高さの配列

// 深さを設定する関数
void setDepth(int u, int d) {
    if (u == NIL) return; // ノードが存在しない場合は終了
    D[u] = d; // 深さを設定
    setDepth(T[u].left, d + 1); // 左の子ノードの深さを設定
    setDepth(T[u].right, d + 1); // 右の子ノードの深さを設定
}

// 高さを設定する関数
int setHeight(int u) {
    int h1 = 0, h2 = 0; // 左右の高さ
    if (T[u].left != NIL)
        h1 = setHeight(T[u].left) + 1; // 左の子ノードの高さを計算
    if (T[u].right != NIL)
        h2 = setHeight(T[u].right) + 1; // 右の子ノードの高さを計算
    return H[u] = (h1 > h2 ? h1 : h2); // 高さを設定
}

// 兄弟ノードを返す関数
int getSibling(int u) {
    if (T[u].parent == NIL) return NIL; // 親がいない場合はNILを返す
    if (T[T[u].parent].left != u && T[T[u].parent].left != NIL)
        return T[T[u].parent].left; // 左の兄弟を返す
    if (T[T[u].parent].right != u && T[T[u].parent].right != NIL)
        return T[T[u].parent].right; // 右の兄弟を返す
    return NIL; // 兄弟が存在しない場合はNILを返す
}

// ノードの情報を表示する関数
void print(int u) {
    printf("node %d: ", u); // ノード番号を表示
    printf("parent = %d, ", T[u].parent); // 親ノードを表示
    printf("sibling = %d, ", getSibling(u)); // 兄弟ノードを表示
    int deg = 0; // 次数を初期化
    if (T[u].left != NIL) deg++; // 左の子ノードが存在する場合は次数を増加
    if (T[u].right != NIL) deg++; // 右の子ノードが存在する場合は次数を増加
    printf("degree = %d, ", deg); // 次数を表示
    printf("depth = %d, ", D[u]); // 深さを表示
    printf("height = %d, ", H[u]); // 高さを表示
    if (T[u].parent == NIL) {
        printf("root\n"); // ルートノードの場合
    } else if (T[u].left == NIL && T[u].right == NIL) {
        printf("leaf\n"); // 葉ノードの場合
    } else {
        printf("internal node\n"); // 内部ノードの場合
    }
}

// メイン関数
int main() {
    int v, l, r, root = 0; // ノードの値、左、右、ルート
    scanf("%d", &n); // ノード数を入力

    // ノードの親を初期化
    for (int i = 0; i < n; i++) T[i].parent = NIL;

    // ノードの左と右を設定
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &l, &r); // ノードの値と子ノードを入力
        T[v].left = l; // 左の子ノードを設定
        T[v].right = r; // 右の子ノードを設定
        if (l != NIL) T[l].parent = v; // 左の子ノードの親を設定
        if (r != NIL) T[r].parent = v; // 右の子ノードの親を設定
    }

    // ルートノードを見つける
    for (int i = 0; i < n; i++) 
        if (T[i].parent == NIL) root = i; 

    setDepth(root, 0); // 深さを設定
    setHeight(root); // 高さを設定

    // 各ノードの情報を表示
    for (int i = 0; i < n; i++) print(i); 

    return 0; // プログラムを終了
}
