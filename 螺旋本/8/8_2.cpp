#include <iostream>
using namespace std;
#define MAX 100005  // 扱うノードの最大数
#define NIL -1      // ノードが存在しないことを示すための特殊値

// 木構造のノードを表す構造体
struct Node {
    int p;  // 親ノードのインデックス（存在しない場合はNIL）
    int l;  // 左の子ノードのインデックス（存在しない場合はNIL）
    int r;  // 右の子ノードのインデックス（存在しない場合はNIL）
};

Node T[MAX];  // 木のノードを格納する配列
int n, D[MAX];  // nはノードの数、Dは各ノードの深さを格納する配列

// ノードの情報を表示する関数
void print(int u) {
    int i, c;
    cout << "node " << u << ": ";          // ノード番号の出力
    cout << "parent = " << T[u].p << ", "; // 親ノードのインデックスの出力
    cout << "depth = " << D[u] << ", ";    // ノードの深さの出力

    // ノードの種類（root, leaf, internal node）の判定
    if (T[u].p == NIL) cout << "root, ";               // 親がNILなら根ノード
    else if (T[u].l == NIL) cout << "leaf, ";           // 左の子がNILなら葉ノード
    else cout << "internal node, ";                     // それ以外は内部ノード

    // 子ノードのリストを出力
    cout << "[";
    for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) { // 左の子から順に表示
        if (i) cout << ",";                             // 2つ目以降の子はカンマで区切る
        cout << c;                                      // 子ノードのインデックスを表示
    }
    cout << "]" << endl;
}

// ノードの深さを再帰的に計算する関数
int rec(int u, int p) {
    D[u] = p;  // 現在のノードの深さを記録
    if (T[u].r != NIL) rec(T[u].r, p);      // 右の兄弟がいる場合、同じ深さで再帰
    if (T[u].l != NIL) rec(T[u].l, p + 1);  // 左の子がいる場合、深さを1増やして再帰
}

int main() {
    /*
    i,j:ループに使う
    d:ノードの子供の数
    v:ノード番号
    c:子ノードの番号
    l,r:左右の子
    */
    int i, j, d, v, c, l, r;

    // ノード数の入力
    cin >> n;

    // 全ノードの親・左の子・右の子をNILに初期化
    for (i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;

    // ノードの情報を入力
    for (i = 0; i < n; i++) {
        cin >> v >> d;  // vはノード番号、dはそのノードの子供の数
        for (j = 0; j < d; j++) {
            cin >> c;  // cは子ノードの番号
            if (j == 0) T[v].l = c;  // 最初の子を左の子に設定
            else T[v].r = c;         // それ以外の子を右の兄弟に設定
            l = c;                   // 子ノードを記録
            T[c].p = v;              // 子ノードの親をvに設定
        }
    }

    // 根ノードを探す（親がNILのノードが根）
    for (i = 0; i < n; i++) {
        if (T[i].p == NIL) r = i;
    }

    // 深さの計算を再帰的に実行
    rec(r, 0);

    // 全ノードの情報を出力
    for (i = 0; i < n; i++) print(i);

    return 0;
}
