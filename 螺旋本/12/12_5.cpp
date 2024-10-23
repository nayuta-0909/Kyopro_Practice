#include <iostream>    // 標準入出力用ライブラリ
#include <vector>      // 動的配列（ベクトル）を使用するためのライブラリ
#include <stack>       // スタックを使用するためのライブラリ
using namespace std;

static const int MAX = 100000;  // 頂点の最大数を設定
static const int NIL = -1;      // 訪問状態が未確定なことを示す定数

int n;                         // 頂点数
vector<int> G[MAX];            // グラフの隣接リスト（動的配列）
int color[MAX];                // 各頂点の色（連結成分のグループ）を管理する配列

// 深さ優先探索 (DFS) を行い、連結成分の色を割り当てる
void dfs(int r, int c) {
    stack<int> S;      // 深さ優先探索用のスタック
    S.push(r);         // 開始頂点をスタックに追加
    color[r] = c;      // 開始頂点の色を設定

    while (!S.empty()) {  // スタックが空になるまでループ
        int u = S.top();  // スタックの最上位の頂点uを取得
        S.pop();          // スタックから削除
        for (int i = 0; i < G[u].size(); i++) {  // 頂点uに隣接する全ての頂点vを探索
            int v = G[u][i];
            if (color[v] == NIL) {  // 頂点vがまだ訪問されていない場合
                color[v] = c;       // 頂点vに色を割り当て
                S.push(v);          // 頂点vをスタックに追加
            }
        }
    }
}

// グラフ全体に対して連結成分の色を割り当てる関数
void assignColor() {
    int id = 1;  // 連結成分の識別子（色）
    for (int i = 0; i < n; i++) color[i] = NIL;  // すべての頂点の色を未確定に初期化
    for (int u = 0; u < n; u++) {  // 全ての頂点uについて
        if (color[u] == NIL) dfs(u, id++);  // 未訪問の頂点に対してDFSを行い、色を割り当てる
    }
}

int main() {
    int s, t, m, q;

    cin >> n >> m;  // 頂点数nと辺の数mを入力
    for (int i = 0; i < m; i++) {
        cin >> s >> t;  // 辺の両端点sとtを入力
        s--; t--;       // 頂点番号を0始まりに変換
        G[s].push_back(t);  // 頂点sの隣接リストにtを追加
        G[t].push_back(s);  // 頂点tの隣接リストにsを追加（無向グラフなので双方向に追加）
    }

    assignColor();  // グラフ全体に連結成分の色を割り当てる

    cin >> q;  // クエリの数qを入力
    for (int i = 0; i < q; i++) {
        cin >> s >> t;  // 頂点sとtについて、連結かどうかを確認する
        s--; t--;       // 頂点番号を0始まりに変換
        if (color[s] == color[t]) {  // sとtが同じ色なら、同じ連結成分に属する
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
