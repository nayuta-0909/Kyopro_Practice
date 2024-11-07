#include<iostream> // 標準入力・出力を扱うライブラリ
using namespace std; // 標準ライブラリの名前空間を使う

static const int MAX = 100; // 最大ノード数
static const int INFTY = (1<<21); // 無限大（大きな数）
static const int WHITE = 0; // 未訪問ノード
static const int GRAY = 1; // 訪問中のノード
static const int BLACK = 2; // 訪問完了ノード

int n, M[MAX][MAX]; // ノード数nと隣接行列M

// プリム法を使って最小全域木を求める関数
int prim() {
    int u, minv;
    int d[MAX], p[MAX], color[MAX]; // 各ノードの最短距離d、前のノードp、色を格納するcolor

    //初期化
    for (int i = 0; i < n; i++) {
        d[i] = INFTY; // 初期化: 全てのノードの距離を無限大に
        p[i] = -1; // 前のノードを初期化
        color[i] = WHITE; // ノードを未訪問に初期化
    }
    d[0] = 0; // 最初のノードの距離を0に

    //最短距離のループ
    while (1) {
        minv = INFTY;
        u = -1;
        
        // 未訪問ノードの中で最小距離のノードuを選ぶ
        for (int i = 0; i < n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }

        if (u == -1) break; // uが見つからない場合、終了

        color[u] = BLACK; // ノードuを訪問完了とする

        // uに隣接する全てのノードvに対して距離を更新
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && M[u][v] != INFTY) {
                if (d[v] > M[u][v]) {
                    d[v] = M[u][v]; // 距離を更新
                    p[v] = u; // vの前のノードをuに
                    color[v] = GRAY; // ノードvを訪問中に設定
                }
            }
        }
    }

    int sum = 0; // 最小全域木の合計コスト
    // 最小全域木のコストを計算
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) sum += M[i][p[i]]; // 経路のコストを合計
    }

    return sum; // 合計コストを返す
}

int main() {
    cin >> n; // ノード数nを入力

    // 隣接行列Mを入力
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int e;
            cin >> e;
            M[i][j] = (e == -1) ? INFTY : e; // 無効な辺は無限大に
        }
    }

    cout << prim() << endl; // 最小全域木のコストを出力
    return 0;
}


